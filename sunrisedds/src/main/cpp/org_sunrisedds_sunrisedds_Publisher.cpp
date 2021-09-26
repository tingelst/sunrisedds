#include "org_sunrisedds_sunrisedds_Publisher.h"
#include <dds/dds.h>

JNIEXPORT jint JNICALL
Java_org_sunrisedds_sunrisedds_Publisher_nativeCreatePublisherHandle(
  JNIEnv *, jclass, jint jparticipant)
{
  dds_entity_t participant = static_cast<dds_entity_t>(jparticipant);
  dds_entity_t publisher = dds_create_publisher(participant, NULL, NULL);
  jint jpublisher = static_cast<jint>(publisher);
  return jpublisher;
}