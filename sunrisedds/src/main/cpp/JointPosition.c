/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: JointPosition.c
  Source: JointPosition.idl
  Cyclone DDS: V0.8.0

*****************************************************************/
#include "JointPosition.h"

static const uint32_t sunrisedds_interfaces_msg_JointPosition_ops [] =
{
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (sunrisedds_interfaces_msg_JointPosition, header.stamp.sec),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (sunrisedds_interfaces_msg_JointPosition, header.stamp.nanosec),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (sunrisedds_interfaces_msg_JointPosition, header.frame_id),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_JointPosition, position.a1),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_JointPosition, position.a2),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_JointPosition, position.a3),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_JointPosition, position.a4),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_JointPosition, position.a5),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_JointPosition, position.a6),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_JointPosition, position.a7),
  DDS_OP_RTS
};

const dds_topic_descriptor_t sunrisedds_interfaces_msg_JointPosition_desc =
{
  sizeof (sunrisedds_interfaces_msg_JointPosition),
  sizeof (char *),
  DDS_TOPIC_NO_OPTIMIZE,
  0u,
  "sunrisedds_interfaces::msg::dds_::JointPosition_",
  NULL,
  11,
  sunrisedds_interfaces_msg_JointPosition_ops,
  ""
};
