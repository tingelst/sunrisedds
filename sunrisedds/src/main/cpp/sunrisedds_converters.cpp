#include "sunrisedds_signatures.h"
#include "sunrisedds_converters.h"

void *
convert_object_field(JNIEnv * env, jobject message, const char * name, const char * signature)
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
convert_string_field(JNIEnv * env, jobject message, const std::string & name)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "Ljava/lang/String;");
  jstring jstr = static_cast<jstring>(env->GetObjectField(message, fid));
  std::string str{env->GetStringUTFChars(jstr, 0)};
  return str;
}

double
convert_double_field(JNIEnv * env, jobject message, const std::string & name)
{
  return static_cast<double>(
    env->GetDoubleField(message, env->GetFieldID(env->GetObjectClass(message), name.c_str(), "D")));
}

int
convert_int_field(JNIEnv * env, jobject message, const std::string & name)
{
  return static_cast<int>(
    env->GetIntField(message, env->GetFieldID(env->GetObjectClass(message), name.c_str(), "I")));
}