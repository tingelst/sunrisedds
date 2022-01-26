#include <dds/dds.h>

#include "Time.h"
#include "no_ntnu_mtp_ra_sunrisedds_msg_Time.h"
#include "sunrisedds_converters.h"

JavaVM * g_vm = nullptr;

builtin_interfaces_msg_Time *
builtin_interfaces_msg_Time__convert_from_java(
  jobject jmessage, builtin_interfaces_msg_Time * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = builtin_interfaces_msg_Time__alloc();
  }

  message->sec = static_cast<int32_t>(get_int_field(env, jmessage, "sec"));
  message->nanosec = static_cast<uint32_t>(
    get_int_field(env, jmessage, "nanosec"));  // TODO(tingelst): Could overflow

  return message;
}

jobject
builtin_interfaces_msg_Time__convert_to_java(
  builtin_interfaces_msg_Time * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/msg/Time");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");

  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  set_int_field(env, jmessage, "sec", message->sec);
  set_int_field(env, jmessage, "nanosec", message->nanosec);

  return jmessage;
}

void
builtin_interfaces_msg_Time__destroy(builtin_interfaces_msg_Time * message)
{
  builtin_interfaces_msg_Time_free(message, DDS_FREE_ALL);
}

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getFromJavaConverter
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&builtin_interfaces_msg_Time__convert_from_java);
  return ptr;
}

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getToJavaConverter
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&builtin_interfaces_msg_Time__convert_to_java);
  return ptr;
}

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getTopicDescriptor
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  return reinterpret_cast<jlong>(&builtin_interfaces_msg_Time_desc);
}

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getDestructor
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&builtin_interfaces_msg_Time__destroy);
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