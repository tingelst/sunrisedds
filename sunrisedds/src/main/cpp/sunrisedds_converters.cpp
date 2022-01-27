// Copyright 2022 Norwegian University of Science and Technology.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

void *
get_object_field(JNIEnv * env, jobject message, const char * name, const char * signature)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name, signature);
  jobject object = env->GetObjectField(message, fid);
  jclass object_class = env->GetObjectClass(object);
  jmethodID from_java_mid = env->GetStaticMethodID(object_class, "getFromJavaConverter", "()J");
  jlong from_java_converter = env->CallStaticLongMethod(object_class, from_java_mid);
  convert_from_java_signature convert_from_java =
    reinterpret_cast<convert_from_java_signature>(from_java_converter);
  return convert_from_java(object, nullptr);
}

std::string
get_string_field(JNIEnv * env, jobject message, const std::string & name)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "Ljava/lang/String;");
  jstring jstr = static_cast<jstring>(env->GetObjectField(message, fid));
  std::string str{env->GetStringUTFChars(jstr, 0)};
  return str;
}

double
get_double_field(JNIEnv * env, jobject message, const std::string & name)
{
  return static_cast<double>(
    env->GetDoubleField(message, env->GetFieldID(env->GetObjectClass(message), name.c_str(), "D")));
}

int
get_int_field(JNIEnv * env, jobject message, const std::string & name)
{
  return static_cast<int>(
    env->GetIntField(message, env->GetFieldID(env->GetObjectClass(message), name.c_str(), "I")));
}

void
set_object_field(
  JNIEnv * env, jobject jmessage, const std::string & name, const std::string & signature,
  void * field)
{
  jclass jmessage_class = env->GetObjectClass(jmessage);
  jfieldID jfid = env->GetFieldID(jmessage_class, name.c_str(), signature.c_str());
  jclass object_class = env->GetObjectClass(env->GetObjectField(jmessage, jfid));
  jmethodID jto_mid = env->GetStaticMethodID(object_class, "getToJavaConverter", "()J");
  jlong jto_java_converter = env->CallStaticLongMethod(object_class, jto_mid);
  convert_to_java_signature convert_to_java =
    reinterpret_cast<convert_to_java_signature>(jto_java_converter);
  jobject object = convert_to_java(field, nullptr);
  env->SetObjectField(jmessage, jfid, object);
}

void
set_string_field(
  JNIEnv * env, jobject jmessage, const std::string & name, const std::string & field)
{
  jfieldID fid = env->GetFieldID(env->GetObjectClass(jmessage), name.c_str(), "Ljava/lang/String;");
  env->SetObjectField(jmessage, fid, env->NewStringUTF(field.c_str()));
}

void
set_double_field(JNIEnv * env, jobject jmessage, const std::string & name, double field)
{
  jfieldID fid = env->GetFieldID(env->GetObjectClass(jmessage), name.c_str(), "D");
  env->SetDoubleField(jmessage, fid, field);
}

void
set_int_field(JNIEnv * env, jobject jmessage, const std::string & name, int field)
{
  jfieldID fid = env->GetFieldID(env->GetObjectClass(jmessage), name.c_str(), "I");
  env->SetIntField(jmessage, fid, field);
}

void
get_string_array_field(
  JNIEnv * env, jobject message, const std::string & name, dds_sequence_string * out)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "Ljava/util/List;");

  jclass list_class = env->FindClass("java/util/List");
  jmethodID get_mid = env->GetMethodID(list_class, "get", "(I)Ljava/lang/Object;");
  jmethodID size_mid = env->GetMethodID(list_class, "size", "()I");

  jobject list_object = env->GetObjectField(message, fid);
  if (list_object != nullptr) {
    jint length = env->CallIntMethod(list_object, size_mid);
    out->_buffer = dds_sequence_string_allocbuf(length);
    out->_length = length;
    out->_release = true;
    for (int i = 0; i < length; ++i) {
      jstring element = static_cast<jstring>(env->CallObjectMethod(list_object, get_mid, i));
      if (element != nullptr) {
        const char * str = env->GetStringUTFChars(element, 0);
        out->_buffer[i] = dds_string_dup(str);
        env->ReleaseStringUTFChars(element, str);
      }
      env->DeleteLocalRef(element);
    }
  }
}

void
get_double_array_field(
  JNIEnv * env, jobject message, const std::string & name, dds_sequence_double * out)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "Ljava/util/List;");

  jclass list_class = env->FindClass("java/util/List");
  jmethodID list_get_mid = env->GetMethodID(list_class, "get", "(I)Ljava/lang/Object;");
  jmethodID list_size_mid = env->GetMethodID(list_class, "size", "()I");

  jclass double_class = env->FindClass("java/lang/Double");
  jmethodID double_value_mid = env->GetMethodID(double_class, "doubleValue", "()D");

  jobject list_object = env->GetObjectField(message, fid);
  if (list_object != nullptr) {
    jint length = env->CallIntMethod(list_object, list_size_mid);
    out->_buffer = dds_sequence_double_allocbuf(length);
    out->_length = length;
    out->_release = true;
    for (int i = 0; i < length; ++i) {
      jobject element = env->CallObjectMethod(list_object, list_get_mid, i);
      if (element != nullptr) {
        out->_buffer[i] = env->CallDoubleMethod(element, double_value_mid);
      }
      env->DeleteLocalRef(element);
    }
  }
}

void
set_double_array_field(
  JNIEnv * env, jobject jmessage, const std::string & name, dds_sequence_double * field)
{
  jclass message_class = env->GetObjectClass(jmessage);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "Ljava/util/List;");

  jclass array_list_class = env->FindClass("java/util/ArrayList");
  jmethodID array_list_constructor_mid = env->GetMethodID(array_list_class, "<init>", "()V");
  jmethodID array_list_add_mid = env->GetMethodID(array_list_class, "add", "(Ljava/lang/Object;)Z");
  jobject array_list_object = env->NewObject(array_list_class, array_list_constructor_mid);

  jclass double_object_class = env->FindClass("java/lang/Double");
  jmethodID double_object_constructor_mid = env->GetMethodID(double_object_class, "<init>", "(D)V");

  jobject array_list = env->NewObject(array_list_class, array_list_constructor_mid);
  if (array_list != nullptr) {
    for (int i = 0; i < field->_length; ++i) {
      jobject double_object =
        env->NewObject(double_object_class, double_object_constructor_mid, field->_buffer[i]);
      if (double_object != nullptr) {
        jboolean result = env->CallBooleanMethod(array_list, array_list_add_mid, double_object);
        assert(result);
      }
      env->DeleteLocalRef(double_object);
    }
  }
  env->SetObjectField(jmessage, fid, array_list);
}

void
set_string_array_field(
  JNIEnv * env, jobject jmessage, const std::string & name, dds_sequence_string * field)
{
  jclass message_class = env->GetObjectClass(jmessage);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "Ljava/util/List;");

  jclass array_list_class = env->FindClass("java/util/ArrayList");
  jmethodID array_list_constructor_mid = env->GetMethodID(array_list_class, "<init>", "()V");
  jmethodID array_list_add_mid = env->GetMethodID(array_list_class, "add", "(Ljava/lang/Object;)Z");

  jobject array_list = env->NewObject(array_list_class, array_list_constructor_mid);
  if (array_list != nullptr) {
    for (int i = 0; i < field->_length; ++i) {
      jstring string_object = env->NewStringUTF(field->_buffer[i]);
      if (string_object != nullptr) {
        jboolean result = env->CallBooleanMethod(array_list, array_list_add_mid, string_object);
        assert(result);
      }
      env->DeleteLocalRef(string_object);
    }
  }
  env->SetObjectField(jmessage, fid, array_list);
}
