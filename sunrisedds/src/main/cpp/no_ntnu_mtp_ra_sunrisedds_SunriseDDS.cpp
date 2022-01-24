#include <dds/dds.h>

#include "no_ntnu_mtp_ra_sunrisedds_SunriseDDS.h"

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDomainParticipant(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  dds_entity_t participant = dds_create_participant(DDS_DOMAIN_DEFAULT, NULL, NULL);
  return static_cast<jint>(participant);
}

JNIEXPORT jint JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreatePublisher(
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
Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateSubscriber(
  JNIEnv * env, jclass cls, jint jparticipant)
{
  (void)env;
  (void)cls;
  dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);
  dds_entity_t subscriber = dds_create_subscriber(participant, NULL, NULL);
  jint jsubscriber = static_cast<jint>(subscriber);
  return jsubscriber;
}
