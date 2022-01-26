#include "no_ntnu_mtp_ra_sunrisedds_msg_JointPosition.h"
#include <dds/dds.h>
#include "JointPosition.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

JavaVM * g_vm = nullptr;

sunrisedds_interfaces_msg_JointPosition *
sunrisedds_interfaces_msg_JointPosition__convert_from_java(
  jobject jmessage, sunrisedds_interfaces_msg_JointPosition * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = sunrisedds_interfaces_msg_JointPosition__alloc();
  }

  message->header = *reinterpret_cast<std_msgs_msg_Header *>(
    get_object_field(env, jmessage, "header", "Lno/ntnu/mtp/ra/sunrisedds/msg/Header;"));

  message->position = *reinterpret_cast<sunrisedds_interfaces_msg_JointQuantity *>(
    get_object_field(env, jmessage, "position", "Lno/ntnu/mtp/ra/sunrisedds/msg/JointQuantity;"));

  return message;
}

jobject
sunrisedds_interfaces_msg_JointPosition__convert_to_java(
  sunrisedds_interfaces_msg_JointPosition * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/msg/JointPosition");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");
  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  set_object_field(
    env, jmessage, "header", "Lno/ntnu/mtp/ra/sunrisedds/msg/Header;", &message->header);
  set_object_field(
    env, jmessage, "position", "Lno/ntnu/mtp/ra/sunrisedds/msg/JointQuantity;", &message->position);

  return jmessage;
}

void
sunrisedds_interfaces_msg_JointPosition__destroy(sunrisedds_interfaces_msg_JointPosition * message)
{
  sunrisedds_interfaces_msg_JointPosition_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointPosition_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointPosition__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointPosition_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointPosition__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointPosition_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointPosition_desc);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointPosition_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointPosition__destroy);
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
