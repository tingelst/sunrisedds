#include "no_ntnu_mtp_ra_sunrisedds_msg_JointState.h"
#include <dds/dds.h>
#include "JointState.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

#include <vector>

JavaVM * g_vm = nullptr;

std::vector<double>
get_double_array_field(JNIEnv * env, jobject message, const std::string & name)
{
  jclass message_class = env->GetObjectClass(message);
  jfieldID fid = env->GetFieldID(message_class, name.c_str(), "[D");
  jdoubleArray object = static_cast<jdoubleArray>(env->GetObjectField(message, fid));
  jsize length = env->GetArrayLength(object);
  jdouble * array = env->GetDoubleArrayElements(object, 0);
  std::vector<double> ret(length);
  for (size_t i = 0; i < length; ++i) {
    ret[i] = array[i];
  }
  return std::vector<double>();
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

  std::vector<double> position = get_double_array_field(env, jmessage, "position");
//   message->position = *dds_sequence_double__alloc();
  message->position._buffer = dds_sequence_double_allocbuf(position.size());
  message->position._length = position.size();
  message->position._release = true;
  for (size_t i = 0; i < position.size(); ++i) {
    message->position._buffer[i] = position[i];
  }

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
