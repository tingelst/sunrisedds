#include "no_ntnu_mtp_ra_sunrisedds_msg_JointState.h"
#include <dds/dds.h>
#include "JointState.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

#include <vector>

JavaVM * g_vm = nullptr;

void
get_string_array_field(
  JNIEnv * env, jobject message, const std::string & name, dds_sequence_string * out)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "[Ljava/lang/String;");
  jobjectArray string_array = static_cast<jobjectArray>(env->GetObjectField(message, fid));
  jsize length = env->GetArrayLength(string_array);

  out->_buffer = dds_sequence_string_allocbuf(length);
  out->_length = length;
  out->_release = true;
  for (size_t i = 0; i < length; ++i) {
    jstring str = static_cast<jstring>(env->GetObjectArrayElement(string_array, i));
    out->_buffer[i] = dds_string_dup(env->GetStringUTFChars(str, 0));
  }
}

void
get_double_array_field(
  JNIEnv * env, jobject message, const std::string & name, dds_sequence_double * out)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "[D");
  jdoubleArray object = static_cast<jdoubleArray>(env->GetObjectField(message, fid));
  jsize length = env->GetArrayLength(object);
  jdouble * array = env->GetDoubleArrayElements(object, 0);

  out->_buffer = dds_sequence_double_allocbuf(length);
  out->_length = length;
  out->_release = true;
  for (size_t i = 0; i < length; ++i) {
    out->_buffer[i] = array[i];
  }
}

sensor_msgs_msg_JointState *
sensor_msgs_msg_JointState__convert_from_java(
  jobject jmessage, sensor_msgs_msg_JointState * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = sensor_msgs_msg_JointState__alloc();
  }

  message->header = *reinterpret_cast<std_msgs_msg_Header *>(
    get_object_field(env, jmessage, "header", "Lno/ntnu/mtp/ra/sunrisedds/msg/Header;"));

  get_string_array_field(env, jmessage, "name", &message->name);
  get_double_array_field(env, jmessage, "position", &message->position);
  get_double_array_field(env, jmessage, "velocity", &message->velocity);
  get_double_array_field(env, jmessage, "effort", &message->effort);

  return message;
}

jobject
sensor_msgs_msg_JointState__convert_to_java(sensor_msgs_msg_JointState * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/msg/JointState");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");
  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  return jmessage;
}

void
sensor_msgs_msg_JointState__destroy(sensor_msgs_msg_JointState * message)
{
  sensor_msgs_msg_JointState_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointState_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sensor_msgs_msg_JointState__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointState_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sensor_msgs_msg_JointState__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointState_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sensor_msgs_msg_JointState_desc);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointState_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sensor_msgs_msg_JointState__destroy);
  return ptr;
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM * vm, void *)
{
  // Can only call this once
  if (g_vm == nullptr) {
    g_vm = vm;
  }

  return JNI_VERSION_1_6;
}
