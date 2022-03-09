/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: ServoCommand.h
  Source: ServoCommand.idl
  Cyclone DDS: V0.8.0

*****************************************************************/
#ifndef DDSC_SERVOCOMMAND_H
#define DDSC_SERVOCOMMAND_H

#include "Header.h"

#include "DirectServo.h"

#include "SmartServo.h"

#include "SmartServoLin.h"

#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define sunrisedds_interfaces_msg_ServoCommand_Constants_SMART_SERVO 0
#define sunrisedds_interfaces_msg_ServoCommand_Constants_DIRECT_SERVO 1
#define sunrisedds_interfaces_msg_ServoCommand_Constants_SMART_SERVO_LIN 2
typedef struct sunrisedds_interfaces_msg_ServoCommand
{
  std_msgs_msg_Header header;
  uint8_t type;
  sunrisedds_interfaces_msg_SmartServo smart_servo;
  sunrisedds_interfaces_msg_DirectServo direct_servo;
  sunrisedds_interfaces_msg_SmartServoLin smart_servo_lin;
} sunrisedds_interfaces_msg_ServoCommand;

extern const dds_topic_descriptor_t sunrisedds_interfaces_msg_ServoCommand_desc;

#define sunrisedds_interfaces_msg_ServoCommand__alloc() \
((sunrisedds_interfaces_msg_ServoCommand*) dds_alloc (sizeof (sunrisedds_interfaces_msg_ServoCommand)));

#define sunrisedds_interfaces_msg_ServoCommand_free(d,o) \
dds_sample_free ((d), &sunrisedds_interfaces_msg_ServoCommand_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_SERVOCOMMAND_H */
