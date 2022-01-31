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

#include "no_ntnu_mtp_ra_sunrisedds_SunriseDDS.h"
#include "sunrisedds_exceptions.h"
#include "sunrisedds_signatures.h"

JavaVM * g_vm = nullptr;
jobject g_on_data_available_callback;

#define MAX_SAMPLES 1

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDomainParticipantHandle(
  JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  dds_entity_t participant = dds_create_participant(DDS_DOMAIN_DEFAULT, NULL, NULL);
  if (participant < 0) {
    std::string error_message =
      std::string{"dds_create_participant: "} + std::string{dds_strretcode(-participant)};
    return sunrisedds_throw_exception(env, error_message);
  }
  return static_cast<jint>(participant);
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreatePublisherHandle(
  JNIEnv * env, jclass cls, jint jparticipant)
{
  (void)env;
  (void)cls;
  dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);
  dds_entity_t publisher = dds_create_publisher(participant, NULL, NULL);
  if (publisher < 0) {
    std::string error_message =
      std::string{"dds_create_publisher: "} + std::string{dds_strretcode(-publisher)};
    return sunrisedds_throw_exception(env, error_message);
  }
  jint jpublisher = static_cast<jint>(publisher);
  return jpublisher;
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateSubscriberHandle(
  JNIEnv * env, jclass cls, jint jparticipant)
{
  (void)env;
  (void)cls;
  dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);
  dds_entity_t subscriber = dds_create_subscriber(participant, NULL, NULL);
  if (subscriber < 0) {
    std::string error_message =
      std::string{"dds_create_subscriber: "} + std::string{dds_strretcode(-subscriber)};
    return sunrisedds_throw_exception(env, error_message);
  }
  jint jsubscriber = static_cast<jint>(subscriber);
  return jsubscriber;
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateTopicHandle(
  JNIEnv * env, jclass cls, jint jparticipant, jclass jmessage_class, jstring jtopic_name)
{
  (void)cls;

  jmethodID mid = env->GetStaticMethodID(jmessage_class, "getTopicDescriptor", "()J");
  jlong jtopic_descriptor = env->CallStaticLongMethod(jmessage_class, mid);

  const char * topic_name = env->GetStringUTFChars(jtopic_name, 0);

  dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);

  dds_topic_descriptor_t * td = reinterpret_cast<dds_topic_descriptor_t *>(jtopic_descriptor);

  dds_entity_t topic = dds_create_topic(participant, td, topic_name, NULL, NULL);
  if (topic < 0) {
    std::string error_message =
      std::string{"dds_create_topic: "} + std::string{dds_strretcode(-topic)};
    return sunrisedds_throw_exception(env, error_message);
  }

  env->ReleaseStringUTFChars(jtopic_name, topic_name);

  jint jtopic = static_cast<jint>(topic);
  return jtopic;
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDataWriterHandle(
  JNIEnv * env, jclass cls, jint jparticipant_or_publisher, jint jtopic)
{
  (void)env;
  (void)cls;
  dds_entity_t participant_or_publisher = static_cast<dds_entity_t>(jparticipant_or_publisher);
  dds_entity_t topic = static_cast<dds_entity_t>(jtopic);
  dds_entity_t writer = dds_create_writer(participant_or_publisher, topic, NULL, NULL);
  if (writer < 0) {
    std::string error_message =
      std::string{"dds_create_writer: "} + std::string{dds_strretcode(-writer)};
    return sunrisedds_throw_exception(env, error_message);
  }
  jint jwriter = static_cast<jint>(writer);
  return jwriter;
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDataReaderHandle(
  JNIEnv * env, jclass cls, jint jparticipant_or_subscriber, jint jtopic)
{
  (void)env;
  (void)cls;
  dds_entity_t participant_or_subscriber = static_cast<dds_entity_t>(jparticipant_or_subscriber);
  dds_entity_t topic = static_cast<dds_entity_t>(jtopic);

  dds_qos_t * qos = dds_create_qos();
  dds_qset_reliability(qos, DDS_RELIABILITY_RELIABLE, DDS_SECS(10));
  dds_entity_t reader = dds_create_reader(participant_or_subscriber, topic, qos, NULL);

  if (reader < 0) {
    std::string error_message =
      std::string{"dds_create_reader: "} + std::string{dds_strretcode(-reader)};
    return sunrisedds_throw_exception(env, error_message);
  }
  dds_delete_qos(qos);

  jint jreader = static_cast<jint>(reader);
  return jreader;
}

JNIEXPORT void JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeWrite(
  JNIEnv * env, jclass cls, jint jwriter, jobject jmessage)
{
  (void)cls;
  dds_entity_t writer = static_cast<dds_entity_t>(jwriter);
  jclass jmessage_class = env->GetObjectClass(jmessage);
  jmethodID mid = env->GetStaticMethodID(jmessage_class, "getFromJavaConverter", "()J");
  jlong jfrom_java_converter = env->CallStaticLongMethod(jmessage_class, mid);
  convert_from_java_signature convert_from_java =
    reinterpret_cast<convert_from_java_signature>(jfrom_java_converter);
  void * msg = convert_from_java(jmessage, nullptr);
  dds_return_t ret = dds_write(writer, msg);
  if (ret != DDS_RETCODE_OK) {
    std::string error_message = std::string{"dds_write: "} + std::string{dds_strretcode(-ret)};
    sunrisedds_throw_exception(env, error_message);
  }
}

#define MAX_SAMPLES 1

JNIEXPORT jobject JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeRead(
  JNIEnv * env, jclass cls, jint jreader, jclass jmessage_class)
{
  (void)cls;
  dds_entity_t reader = static_cast<dds_entity_t>(jreader);
  jmethodID jfrom_mid = env->GetStaticMethodID(jmessage_class, "getFromJavaConverter", "()J");
  jlong jfrom_java_converter = env->CallStaticLongMethod(jmessage_class, jfrom_mid);
  convert_from_java_signature convert_from_java =
    reinterpret_cast<convert_from_java_signature>(jfrom_java_converter);

  jmethodID jconstructor = env->GetMethodID(jmessage_class, "<init>", "()V");
  jobject jmsg = env->NewObject(jmessage_class, jconstructor);

  void * taken_msg = convert_from_java(jmsg, nullptr);

  void * samples[MAX_SAMPLES];
  dds_sample_info_t infos[MAX_SAMPLES];
  dds_return_t rc;

  samples[0] = taken_msg;

  while (true) {
    rc = dds_read(
      reader, samples, infos, MAX_SAMPLES,
      MAX_SAMPLES);  // TODO(tingelst): Make non-blocking and throw
    if ((rc > 0) && (infos[0].valid_data)) {
      break;
    } else {
      dds_sleepfor(DDS_MSECS(20));
    }
  }

  // TODO(tingelst): Implement non-blocking take (dds_take).

  jmethodID jto_mid = env->GetStaticMethodID(jmessage_class, "getToJavaConverter", "()J");
  jlong jto_java_converter = env->CallStaticLongMethod(jmessage_class, jto_mid);
  convert_to_java_signature convert_to_java =
    reinterpret_cast<convert_to_java_signature>(jto_java_converter);

  jobject jtaken_msg = convert_to_java(taken_msg, nullptr);

  jmethodID jdestructor_mid = env->GetStaticMethodID(jmessage_class, "getDestructor", "()J");
  jlong jdestructor_handle = env->CallStaticLongMethod(jmessage_class, jdestructor_mid);

  destroy_message_signature destroy_message =
    reinterpret_cast<destroy_message_signature>(jdestructor_handle);

  destroy_message(taken_msg);

  return jtaken_msg;
}

JNIEXPORT jobject JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeTake(
  JNIEnv * env, jclass cls, jint jreader_or_condition, jclass jmessage_class)
{
  (void)cls;

  dds_entity_t reader_or_condition = static_cast<dds_entity_t>(jreader_or_condition);
  jmethodID jfrom_mid = env->GetStaticMethodID(jmessage_class, "getFromJavaConverter", "()J");
  jlong jfrom_java_converter = env->CallStaticLongMethod(jmessage_class, jfrom_mid);
  convert_from_java_signature convert_from_java =
    reinterpret_cast<convert_from_java_signature>(jfrom_java_converter);

  jmethodID jto_mid = env->GetStaticMethodID(jmessage_class, "getToJavaConverter", "()J");
  jlong jto_java_converter = env->CallStaticLongMethod(jmessage_class, jto_mid);
  convert_to_java_signature convert_to_java =
    reinterpret_cast<convert_to_java_signature>(jto_java_converter);

  jmethodID jdestructor_mid = env->GetStaticMethodID(jmessage_class, "getDestructor", "()J");
  jlong jdestructor_handle = env->CallStaticLongMethod(jmessage_class, jdestructor_mid);
  destroy_message_signature destroy_message =
    reinterpret_cast<destroy_message_signature>(jdestructor_handle);

  jmethodID jconstructor = env->GetMethodID(jmessage_class, "<init>", "()V");
  jobject jmsg = env->NewObject(jmessage_class, jconstructor);

  void * taken_msg = convert_from_java(jmsg, nullptr);

  void * samples[MAX_SAMPLES];
  dds_sample_info_t infos[MAX_SAMPLES];
  dds_return_t rc;

  samples[0] = taken_msg;

  rc = dds_take(reader_or_condition, samples, infos, MAX_SAMPLES, MAX_SAMPLES);
  if (rc < 0) {
    destroy_message(taken_msg);
    std::string error_message = std::string{"dds_take: "} + std::string{dds_strretcode(-rc)};
    sunrisedds_throw_exception(env, error_message);
    return nullptr;
  }

  if ((rc > 0) && (infos[0].valid_data)) {
    jobject jtaken_msg = convert_to_java(taken_msg, nullptr);
    destroy_message(taken_msg);
    return jtaken_msg;
  }

  destroy_message(taken_msg);
  return nullptr;
}

JNIEXPORT void JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeAddOnDataAvailableCallback(
  JNIEnv * env, jclass cls, jint jreader, jobject callback)
{
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateWaitSetHandle(
  JNIEnv * env, jclass cls, jint jparticipant)
{
  (void)cls;
  dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);
  dds_entity_t waitset = dds_create_waitset(participant);
  if (waitset < 0) {
    std::string error_message =
      std::string{"dds_create_waitset: "} + std::string{dds_strretcode(-waitset)};
    return sunrisedds_throw_exception(env, error_message);
  }
  jint jwaitset = static_cast<jint>(waitset);
  return jwaitset;

  DDS_DATA_AVAILABLE_STATUS
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeWaitSetAttach(
  JNIEnv * env, jclass cls, jint jwaitset, jint jentity)
{
  (void)cls;
  dds_entity_t waitset = static_cast<dds_entity_t>(jwaitset);
  dds_entity_t entity = static_cast<dds_entity_t>(jentity);
  dds_return_t ret = dds_waitset_attach(waitset, entity, 0);
  if (ret != DDS_RETCODE_OK) {
    std::string error_message =
      std::string{"dds_waitset_attach: "} + std::string{dds_strretcode(-ret)};
    return sunrisedds_throw_exception(env, error_message);
  }
  jint jret = static_cast<jint>(ret);
  return jret;
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeWaitSetWait(
  JNIEnv * env, jclass cls, jint jwaitset, jlong jreltimeout)
{
  (void)cls;
  dds_entity_t waitset = static_cast<dds_entity_t>(jwaitset);
  dds_duration_t reltimeout = static_cast<dds_duration_t>(jreltimeout);
  dds_return_t ret = dds_waitset_wait(waitset, NULL, 0, reltimeout);
  if (ret < 0) {
    std::string error_message =
      std::string{"dds_waitset_wait: "} + std::string{dds_strretcode(-ret)};
    return sunrisedds_throw_exception(env, error_message);
  }
  jint jret = static_cast<jint>(ret);
  return jret;
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateReadCondition(
  JNIEnv * env, jclass cls, jint jreader, jint jmask)
{
  (void)env;
  (void)cls;

  dds_entity_t reader = static_cast<dds_entity_t>(jreader);
  uint32_t mask = static_cast<uint32_t>(jmask);

  dds_entity_t rc = dds_create_readcondition(reader, mask);
  if (rc < 0) {
    std::string error_message =
      std::string{"dds_create_readcondition: "} + std::string{dds_strretcode(-rc)};
    return sunrisedds_throw_exception(env, error_message);
  }
  jint jrc = static_cast<jint>(rc);
  return jrc;
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM * vm, void *)
{
  // Can only call this once
  if (g_vm == nullptr) {
    g_vm = vm;
  }

  JNIEnv * env;
  if (g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
    return JNI_ERR;
  }

  return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM * vm, void *)
{
  assert(g_vm != nullptr);
  assert(g_vm == vm);

  JNIEnv * env;
  if (g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) == JNI_OK) {
    env->DeleteGlobalRef(g_on_data_available_callback);
  }
}