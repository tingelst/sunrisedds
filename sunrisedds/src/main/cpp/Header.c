#include "Header.h"

static const uint32_t std_msgs_msg_Header_ops [] =
{
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (std_msgs_msg_Header, stamp.sec),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (std_msgs_msg_Header, stamp.nanosec),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (std_msgs_msg_Header, frame_id),
  DDS_OP_RTS
};

const dds_topic_descriptor_t std_msgs_msg_Header_desc =
{
  sizeof (std_msgs_msg_Header),
  sizeof (char *),
  DDS_TOPIC_NO_OPTIMIZE,
  0u,
  "std_msgs::msg::dds_::Header_",
  NULL,
  4,
  std_msgs_msg_Header_ops,
  ""
};
