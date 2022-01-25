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