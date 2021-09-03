/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: JointPosition.h
  Source: JointPosition.idl
  Cyclone DDS: V0.8.0

*****************************************************************/
#ifndef DDSC_JOINTPOSITION_H
#define DDSC_JOINTPOSITION_H

#include "Header.h"

#include "JointQuantity.h"

#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sunrisedds_interfaces_msg_JointPosition
{
  std_msgs_msg_Header header;
  sunrisedds_interfaces_msg_JointQuantity position;
} sunrisedds_interfaces_msg_JointPosition;

extern const dds_topic_descriptor_t sunrisedds_interfaces_msg_JointPosition_desc;

#define sunrisedds_interfaces_msg_JointPosition__alloc() \
((sunrisedds_interfaces_msg_JointPosition*) dds_alloc (sizeof (sunrisedds_interfaces_msg_JointPosition)));

#define sunrisedds_interfaces_msg_JointPosition_free(d,o) \
dds_sample_free ((d), &sunrisedds_interfaces_msg_JointPosition_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_JOINTPOSITION_H */
