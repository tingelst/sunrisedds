#include <dds/dds.h>

#include "JointQuantity.h"
#include "no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity.h"
#include "sunrisedds_signatures.h"
#include "sunrisedds_converters.h"

#include <string>

JavaVM * g_vm = nullptr;


sunrisedds_interfaces_msg_JointQuantity *
sunrisedds_interfaces_msg_JointQuantity__convert_from_java(
  jobject jmessage, sunrisedds_interfaces_msg_JointQuantity * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = sunrisedds_interfaces_msg_JointQuantity__alloc();
  }

  message->a1 = convert_double_field(env, jmessage, "a1");
  message->a2 = convert_double_field(env, jmessage, "a2");
  message->a3 = convert_double_field(env, jmessage, "a3");
  message->a4 = convert_double_field(env, jmessage, "a4");
  message->a5 = convert_double_field(env, jmessage, "a5");
  message->a6 = convert_double_field(env, jmessage, "a6");
  message->a7 = convert_double_field(env, jmessage, "a7");

  return message;
}

jobject
sunrisedds_interfaces_msg_JointQuantity__convert_to_java(
  sunrisedds_interfaces_msg_JointQuantity * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/msg/JointQuantity");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");

  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  env->SetDoubleField(
    jmessage, env->GetFieldID(jmessage_class, "a1", "D"), static_cast<jdouble>(message->a1));
  env->SetDoubleField(
    jmessage, env->GetFieldID(jmessage_class, "a2", "D"), static_cast<jdouble>(message->a2));
  env->SetDoubleField(
    jmessage, env->GetFieldID(jmessage_class, "a3", "D"), static_cast<jdouble>(message->a3));
  env->SetDoubleField(
    jmessage, env->GetFieldID(jmessage_class, "a4", "D"), static_cast<jdouble>(message->a4));
  env->SetDoubleField(
    jmessage, env->GetFieldID(jmessage_class, "a5", "D"), static_cast<jdouble>(message->a5));
  env->SetDoubleField(
    jmessage, env->GetFieldID(jmessage_class, "a6", "D"), static_cast<jdouble>(message->a6));
  env->SetDoubleField(
    jmessage, env->GetFieldID(jmessage_class, "a7", "D"), static_cast<jdouble>(message->a7));

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
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointQuantity__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointQuantity__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  return reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointQuantity_desc);
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointQuantity__destroy);
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
