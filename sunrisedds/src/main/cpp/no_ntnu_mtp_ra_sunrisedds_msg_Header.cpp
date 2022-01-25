#include "no_ntnu_mtp_ra_sunrisedds_msg_Header.h"
#include <dds/dds.h>
#include "Header.h"

using convert_from_java_signature = void * (*)(jobject, void *);
using convert_to_java_signature = jobject (*)(void *, jobject);
using destroy_message_signature = void (*)(void *);

JavaVM * g_vm = nullptr;

std_msgs_msg_Header *
std_msgs_msg_Header__convert_from_java(jobject jmessage, std_msgs_msg_Header * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = std_msgs_msg_Header__alloc();
  }

  jclass jmessage_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/msg/Header");

  jfieldID jstamp_fid =
    env->GetFieldID(jmessage_class, "stamp", "Lno/ntnu/mtp/ra/sunrisedds/msg/Time;");
  jobject jstamp = env->GetObjectField(jmessage, jstamp_fid);
  jclass jstamp_class = env->GetObjectClass(jstamp);
  jmethodID jstamp_from_java_mid =
    env->GetStaticMethodID(jstamp_class, "getFromJavaConverter", "()J");
  jlong jstamp_from_java_converter =
    env->CallStaticLongMethod(jmessage_class, jstamp_from_java_mid);
  convert_from_java_signature convert_stamp_from_java =
    reinterpret_cast<convert_from_java_signature>(jstamp_from_java_converter);
  builtin_interfaces_msg_Time * stamp =
    reinterpret_cast<builtin_interfaces_msg_Time *>(convert_stamp_from_java(jstamp, nullptr));
  message->stamp = *stamp;

  jfieldID jframe_id_fid = env->GetFieldID(jmessage_class, "frameId", "Ljava/lang/String;");
  jstring jframe_id = static_cast<jstring>(env->GetObjectField(jmessage, jframe_id_fid));
  const char * frame_id = env->GetStringUTFChars(jframe_id, 0);
  message->frame_id = dds_string_dup(frame_id);
  env->ReleaseStringUTFChars(jframe_id, frame_id);

  return message;
}

jobject
std_msgs_msg_Header__convert_to_java(std_msgs_msg_Header * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("no/ntnu/mtp/ra/sunrisedds/msg/Header");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");
  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  jfieldID jstamp_fid =
    env->GetFieldID(jmessage_class, "stamp", "Lno/ntnu/mtp/ra/sunrisedds/msg/Time;");
  jobject jstamp = env->GetObjectField(jmessage, jstamp_fid);
  jclass jstamp_class = env->GetObjectClass(jstamp);
  jmethodID jto_mid = env->GetStaticMethodID(jstamp_class, "getToJavaConverter", "()J");
  jlong jto_java_converter = env->CallStaticLongMethod(jmessage_class, jto_mid);
  convert_to_java_signature convert_to_java =
    reinterpret_cast<convert_to_java_signature>(jto_java_converter);
  jstamp = convert_to_java(&message->stamp, nullptr);
  env->SetObjectField(jmessage, jstamp_fid, jstamp);

  jfieldID jframe_id_fid = env->GetFieldID(jmessage_class, "frameId", "Ljava/lang/String;");
  env->SetObjectField(jmessage, jframe_id_fid, env->NewStringUTF(message->frame_id));

  return jmessage;
}

void
std_msgs_msg_Header__destroy(std_msgs_msg_Header * message)
{
  std_msgs_msg_Header_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Header_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  jlong ptr = reinterpret_cast<jlong>(&std_msgs_msg_Header__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Header_getToJavaConverter(JNIEnv * env, jclass cls)
{
  jlong ptr = reinterpret_cast<jlong>(std_msgs_msg_Header__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Header_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  return reinterpret_cast<jlong>(&std_msgs_msg_Header_desc);
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Header_getDestructor(JNIEnv * env, jclass cls)
{
  jlong ptr = reinterpret_cast<jlong>(&std_msgs_msg_Header__destroy);
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