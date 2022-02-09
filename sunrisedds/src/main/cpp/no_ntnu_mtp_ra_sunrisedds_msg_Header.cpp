// Copyright 2022 Norwegian University of Science and Technology.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "no_ntnu_mtp_ra_sunrisedds_msg_Header.h"
#include <dds/dds.h>
#include "Header.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

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

  message->stamp = *reinterpret_cast<builtin_interfaces_msg_Time *>(
    get_object_field(env, jmessage, "stamp", "Lno/ntnu/mtp/ra/sunrisedds/msg/Time;"));

  message->frame_id = dds_string_dup(get_string_field(env, jmessage, "frameId").c_str());

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

  set_object_field(env, jmessage, "stamp", "Lno/ntnu/mtp/ra/sunrisedds/msg/Time;", &message->stamp);
  set_string_field(env, jmessage, "frameId", message->frame_id);

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
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&std_msgs_msg_Header__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Header_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(std_msgs_msg_Header__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Header_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&std_msgs_msg_Header_desc);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Header_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&std_msgs_msg_Header__destroy);
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