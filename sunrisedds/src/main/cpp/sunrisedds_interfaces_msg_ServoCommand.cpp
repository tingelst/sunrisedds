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
#include <dds/dds.h>
#include <jni.h>
#include "ServoCommand.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

JavaVM * g_vm = nullptr;

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getFromJavaConverter(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getToJavaConverter(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getTopicDescriptor(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getDestructor(JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif

sunrisedds_interfaces_msg_ServoCommand *
sunrisedds_interfaces_msg_ServoCommand__convert_from_java(
  jobject jmessage, sunrisedds_interfaces_msg_ServoCommand * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = sunrisedds_interfaces_msg_ServoCommand__alloc();
  }

  message->header = *reinterpret_cast<std_msgs_msg_Header *>(
    get_object_field(env, jmessage, "header", "Lstd_msgs/msg/Header;"));

  message->type = static_cast<uint8_t>(get_int_field(env, jmessage, "type"));

  message->smart_servo = *reinterpret_cast<sunrisedds_interfaces_msg_SmartServo *>(
    get_object_field(env, jmessage, "smartServo", "Lsunrisedds_interfaces/msg/SmartServo;"));

  message->direct_servo = *reinterpret_cast<sunrisedds_interfaces_msg_DirectServo *>(
    get_object_field(env, jmessage, "directServo", "Lsunrisedds_interfaces/msg/DirectServo;"));

  message->smart_servo_lin = *reinterpret_cast<sunrisedds_interfaces_msg_SmartServoLin *>(
    get_object_field(env, jmessage, "smartServoLin", "Lsunrisedds_interfaces/msg/SmartServoLin;"));

  return message;
}

jobject
sunrisedds_interfaces_msg_ServoCommand__convert_to_java(
  sunrisedds_interfaces_msg_ServoCommand * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("sunrisedds_interfaces/msg/ServoCommand");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");
  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  set_object_field(env, jmessage, "header", "Lstd_msgs/msg/Header;", &message->header);

  set_int_field(env, jmessage, "type", message->type);

  set_object_field(
    env, jmessage, "smartServo", "Lsunrisedds_interfaces/msg/SmartServo;", &message->smart_servo);
  set_object_field(
    env, jmessage, "directServo", "Lsunrisedds_interfaces/msg/DirectServo;",
    &message->direct_servo);

  set_object_field(
    env, jmessage, "smartServoLin", "Lsunrisedds_interfaces/msg/SmartServoLin;",
    &message->smart_servo_lin);

  return jmessage;
}

void
sunrisedds_interfaces_msg_ServoCommand__destroy(sunrisedds_interfaces_msg_ServoCommand * message)
{
  sunrisedds_interfaces_msg_ServoCommand_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_ServoCommand__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_ServoCommand__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_ServoCommand_desc);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_ServoCommand_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_ServoCommand__destroy);
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
