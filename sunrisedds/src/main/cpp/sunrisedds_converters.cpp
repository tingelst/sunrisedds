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
