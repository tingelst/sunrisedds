#include <dds/dds.h>

#include "Time.h"
#include "no_ntnu_mtp_ra_sunrisedds_msg_Time.h"

JavaVM * g_vm = nullptr;

builtin_interfaces_msg_Time *
builtin_interfaces_msg_Time__convert_from_java(
  jobject jmessage, builtin_interfaces_msg_Time * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->GetObjectClass(jmessage);

  jfieldID jsec_fid = env->GetFieldID(jmessage_class, "sec", "I");
  jint jsec = env->GetIntField(jmessage, jsec_fid);

  jfieldID jnanosec_fid = env->GetFieldID(jmessage_class, "nanosec", "I");
  jint jnanosec = env->GetIntField(jmessage, jnanosec_fid);

  message = builtin_interfaces_msg_Time__alloc();
  message->sec = static_cast<int32_t>(jsec);
  message->nanosec = static_cast<uint32_t>(jnanosec);  // TODO(tingelst): Could overflow

  return message;
}

jobject builtin_interfaces_msg_Time__convert_to_java()

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getFromJavaConverter
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getFromJavaConverter(JNIEnv * env, jclass cls)
{
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
  return 0;
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
  return 0;
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