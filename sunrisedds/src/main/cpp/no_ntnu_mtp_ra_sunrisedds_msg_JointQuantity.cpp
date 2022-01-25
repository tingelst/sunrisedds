#include <dds/dds.h>

#include "JointQuantity.h"
#include "no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity.h"

using convert_from_java_signature = void * (*)(jobject, void *);
using convert_to_java_signature = jobject (*)(void *, jobject);
using destroy_message_signature = void (*)(void *);

JavaVM * g_vm = nullptr;

sunrisedds_interfaces_msg_JointQuantity *
sunrisedds_interfaces_msg_JointQuantity__convert_from_java(
  jobject jmessage, sunrisedds_interfaces_msg_JointQuantity * message)
{
  return message;
}

jobject
sunrisedds_interfaces_msg_JointQuantity__convert_to_java(
  sunrisedds_interfaces_msg_JointQuantity * message, jobject jmessage)
{
  return jmessage;
}

void
sunrisedds_interfaces_msg_JointQuantity__destroy(sunrisedds_interfaces_msg_JointQuantity * message)
{
  sunrisedds_interfaces_msg_JointQuantity_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity_getFromJavaConverter(JNIEnv * env, jclass cls)
{
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity_getToJavaConverter(JNIEnv * env, jclass cls)
{
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity_getTopicDescriptor(JNIEnv * env, jclass cls)
{
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity_getDestructor(JNIEnv * env, jclass cls)
{
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
