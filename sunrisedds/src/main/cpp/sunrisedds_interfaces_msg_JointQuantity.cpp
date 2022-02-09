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
#include <jni.h>
#include <dds/dds.h>
#include "JointQuantity.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

JavaVM * g_vm = nullptr;

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jlong JNICALL Java_sunrisedds_1interfaces_msg_JointQuantity_getFromJavaConverter
  (JNIEnv *, jclass);

JNIEXPORT jlong JNICALL Java_sunrisedds_1interfaces_msg_JointQuantity_getToJavaConverter
  (JNIEnv *, jclass);

JNIEXPORT jlong JNICALL Java_sunrisedds_1interfaces_msg_JointQuantity_getTopicDescriptor
  (JNIEnv *, jclass);

JNIEXPORT jlong JNICALL Java_sunrisedds_1interfaces_msg_JointQuantity_getDestructor
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif

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

  message->a1 = get_double_field(env, jmessage, "a1");
  message->a2 = get_double_field(env, jmessage, "a2");
  message->a3 = get_double_field(env, jmessage, "a3");
  message->a4 = get_double_field(env, jmessage, "a4");
  message->a5 = get_double_field(env, jmessage, "a5");
  message->a6 = get_double_field(env, jmessage, "a6");
  message->a7 = get_double_field(env, jmessage, "a7");

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

  jclass jmessage_class = env->FindClass("sunrisedds_interfaces/msg/JointQuantity");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");

  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  set_double_field(env, jmessage, "a1", message->a1);
  set_double_field(env, jmessage, "a2", message->a2);
  set_double_field(env, jmessage, "a3", message->a3);
  set_double_field(env, jmessage, "a4", message->a4);
  set_double_field(env, jmessage, "a5", message->a5);
  set_double_field(env, jmessage, "a6", message->a6);
  set_double_field(env, jmessage, "a7", message->a7);

  return jmessage;
}

void
sunrisedds_interfaces_msg_JointQuantity__destroy(sunrisedds_interfaces_msg_JointQuantity * message)
{
  sunrisedds_interfaces_msg_JointQuantity_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_JointQuantity_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointQuantity__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_JointQuantity_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointQuantity__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_JointQuantity_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  return reinterpret_cast<jlong>(&sunrisedds_interfaces_msg_JointQuantity_desc);
}

JNIEXPORT jlong JNICALL
Java_sunrisedds_1interfaces_msg_JointQuantity_getDestructor(JNIEnv * env, jclass cls)
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
