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
#include "no_ntnu_mtp_ra_sunrisedds_msg_JointState.h"
#include <dds/dds.h>
#include "JointState.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

#include <vector>

JavaVM * g_vm = nullptr;

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

  set_object_field(
    env, jmessage, "header", "Lno/ntnu/mtp/ra/sunrisedds/msg/Header;", &message->header);

  set_string_array_field(env, jmessage, "name", &message->name);
  set_double_array_field(env, jmessage, "position", &message->position);
  set_double_array_field(env, jmessage, "velocity", &message->velocity);
  set_double_array_field(env, jmessage, "effort", &message->effort);

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
