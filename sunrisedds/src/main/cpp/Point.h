/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: Point.h
  Source: Point.idl
  Cyclone DDS: V0.8.0

*****************************************************************/
#ifndef DDSC_POINT_H
#define DDSC_POINT_H

#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct geometry_msgs_msg_Point
{
  double x;
  double y;
  double z;
} geometry_msgs_msg_Point;

extern const dds_topic_descriptor_t geometry_msgs_msg_Point_desc;

#define geometry_msgs_msg_Point__alloc() \
((geometry_msgs_msg_Point*) dds_alloc (sizeof (geometry_msgs_msg_Point)));

#define geometry_msgs_msg_Point_free(d,o) \
dds_sample_free ((d), &geometry_msgs_msg_Point_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_POINT_H */
