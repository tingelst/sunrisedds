#include <dds/dds.h>

#include "no_ntnu_mtp_ra_sunrisedds_SunriseDDS.h"

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDomainParticipantHandle(
  JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  dds_entity_t participant = dds_create_participant(DDS_DOMAIN_DEFAULT, NULL, NULL);
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
  dds_entity_t reader = dds_create_reader(participant_or_subscriber, topic, NULL, NULL);
  jint jreader = static_cast<jint>(reader);
  return jreader;
}

using convert_from_java_signature = void * (*)(jobject, void *);
using convert_to_java_signature = jobject (*)(void *, jobject);
using destroy_message_signature = void (*)(void *);

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

  dds_write(writer, msg);
}

#define MAX_SAMPLES 1

JNIEXPORT jobject JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeRead(
  JNIEnv * env, jclass cls, jint jreader, jclass jmessage_class)
{
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
    rc = dds_read(reader, samples, infos, MAX_SAMPLES, MAX_SAMPLES);
    if ((rc > 0) && (infos[0].valid_data)) {
      break;
    } else {
      dds_sleepfor(DDS_MSECS(20));
    }
  }

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