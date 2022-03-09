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
#include "Vector3.h"
#include "sunrisedds_converters.h"
#include "sunrisedds_signatures.h"

JavaVM * g_vm = nullptr;

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jlong JNICALL Java_geometry_1msgs_msg_Vector3_getFromJavaConverter(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL Java_geometry_1msgs_msg_Vector3_getToJavaConverter(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL Java_geometry_1msgs_msg_Vector3_getTopicDescriptor(JNIEnv *, jclass);

JNIEXPORT jlong JNICALL Java_geometry_1msgs_msg_Vector3_getDestructor(JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif

geometry_msgs_msg_Vector3 *
geometry_msgs_msg_Vector3__convert_from_java(
  jobject jmessage, geometry_msgs_msg_Vector3 * message)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  if (message == nullptr) {
    message = geometry_msgs_msg_Vector3__alloc();
  }

  message->x = get_double_field(env, jmessage, "x");
  message->y = get_double_field(env, jmessage, "y");
  message->z = get_double_field(env, jmessage, "z");

  return message;
}

jobject
geometry_msgs_msg_Vector3__convert_to_java(
  geometry_msgs_msg_Vector3 * message, jobject jmessage)
{
  JNIEnv * env = nullptr;
  assert(g_vm != nullptr);
  g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
  assert(env != nullptr);

  jclass jmessage_class = env->FindClass("geometry_msgs/msg/Vector3");
  jmethodID jconstructor_mid = env->GetMethodID(jmessage_class, "<init>", "()V");

  if (jmessage == nullptr) {
    jmessage = env->NewObject(jmessage_class, jconstructor_mid);
  }

  set_double_field(env, jmessage, "x", message->x);
  set_double_field(env, jmessage, "y", message->y);
  set_double_field(env, jmessage, "z", message->z);

  return jmessage;
}

void
geometry_msgs_msg_Vector3__destroy(geometry_msgs_msg_Vector3 * message)
{
  geometry_msgs_msg_Vector3_free(message, DDS_FREE_ALL);
}

JNIEXPORT jlong JNICALL
Java_geometry_1msgs_msg_Vector3_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&geometry_msgs_msg_Vector3__convert_from_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_geometry_1msgs_msg_Vector3_getToJavaConverter(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&geometry_msgs_msg_Vector3__convert_to_java);
  return ptr;
}

JNIEXPORT jlong JNICALL
Java_geometry_1msgs_msg_Vector3_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  return reinterpret_cast<jlong>(&geometry_msgs_msg_Vector3_desc);
}

JNIEXPORT jlong JNICALL
Java_geometry_1msgs_msg_Vector3_getDestructor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  jlong ptr = reinterpret_cast<jlong>(&geometry_msgs_msg_Vector3__destroy);
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
