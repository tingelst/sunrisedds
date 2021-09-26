#include <dds/dds.h>

#include "org_sunrisedds_sunrisedds_DomainParticipant.h"

    
JNIEXPORT jint JNICALL
Java_org_sunrisedds_sunrisedds_DomainParticipant_nativeCreateDomainParticipant(JNIEnv *, jclass)
{
  dds_entity_t participant = dds_create_participant(DDS_DOMAIN_DEFAULT, NULL, NULL);
  return static_cast<jint>(participant);
}



