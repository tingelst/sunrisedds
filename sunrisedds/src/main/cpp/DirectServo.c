/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: DirectServo.c
  Source: DirectServo.idl
  Cyclone DDS: V0.8.0

*****************************************************************/
#include "DirectServo.h"

static const uint32_t sunrisedds_interfaces_msg_DirectServo_ops [] =
{
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (sunrisedds_interfaces_msg_DirectServo, type),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_position.a1),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_position.a2),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_position.a3),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_position.a4),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_position.a5),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_position.a6),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_position.a7),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, cartesian_pose.position.x),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, cartesian_pose.position.y),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, cartesian_pose.position.z),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, cartesian_pose.orientation.x),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, cartesian_pose.orientation.y),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, cartesian_pose.orientation.z),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, cartesian_pose.orientation.w),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_velocity_rel.a1),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_velocity_rel.a2),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_velocity_rel.a3),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_velocity_rel.a4),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_velocity_rel.a5),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_velocity_rel.a6),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (sunrisedds_interfaces_msg_DirectServo, joint_velocity_rel.a7),
  DDS_OP_RTS
};

const dds_topic_descriptor_t sunrisedds_interfaces_msg_DirectServo_desc =
{
  sizeof (sunrisedds_interfaces_msg_DirectServo),
  8u,
  DDS_TOPIC_FIXED_SIZE,
  0u,
  "sunrisedds_interfaces::msg::dds_::DirectServo_",
  NULL,
  23,
  sunrisedds_interfaces_msg_DirectServo_ops,
  ""
};