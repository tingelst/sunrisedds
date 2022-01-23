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
