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
#include "DirectServo.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

JavaVM * g_vm = nullptr;

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_DirectServo_getFromJavaConverter(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_DirectServo_getToJavaConverter(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_DirectServo_getTopicDescriptor(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL Java_sunrisedds_1interfaces_msg_DirectServo_getDestructor(JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif

sunrisedds_interfaces_msg_DirectServo *
sunrisedds_interfaces_msg_DirectServo__convert_from_java(
  jobject jmessage, sunrisedds_interfaces_msg_DirectServo * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = sunrisedds_interfaces_msg_DirectServo__alloc();
  }

  message->type = static_cast<uint8_t>(get_int_field(env, jmessage, "type"));

  message->joint_position = *reinterpret_cast<sunrisedds_interfaces_msg_JointQuantity *>(
    get_object_field(env, jmessage, "jointPosition", "Lsunrisedds_interfaces/msg/JointQuantity;"));

  message->cartesian_pose = *reinterpret_cast<geometry_msgs_msg_Pose *>(
    get_object_field(env, jmessage, "cartesianPose", "Lgeometry_msgs/msg/Pose;"));

  message->joint_velocity_rel =
    *reinterpret_cast<sunrisedds_interfaces_msg_JointQuantity *>(get_object_field(
      env, jmessage, "jointVelocityRel", "Lsunrisedds_interfaces/msg/JointQuantity;"));

  return message;
}

jobject
sunrisedds_interfaces_msg_DirectServo__convert_to_java(
  sunrisedds_interfaces_msg_DirectServo * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("sunrisedds_interfaces/msg/DirectServo");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");
  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  set_int_field(env, jmessage, "type", message->type);

  set_object_field(
    env, jmessage, "jointPosition", "Lsunrisedds_interfaces/msg/JointQuantity;",
    &message->joint_position);

  set_object_field(
    env, jmessage, "cartesianPose", "Lgeometry_msgs/msg/Pose;", &message->cartesian_pose);

  set_object_field(
    env, jmessage, "jointVelocityRel", "Lsunrisedds_interfaces/msg/JointQuantity;",
    &message->joint_velocity_rel);

  return jmessage;
}

void
sunrisedds_interfaces_msg_DirectServo__destroy(sunrisedds_interfaces_msg_DirectServo * message)
{
  sunrisedds_interfaces_msg_DirectServo_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_DirectServo_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_DirectServo__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_DirectServo_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_DirectServo__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_DirectServo_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_DirectServo_desc);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_DirectServo_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_DirectServo__destroy);
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
