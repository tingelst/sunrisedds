#include <dds/dds.h>

#include "Time.h"
#include "no_ntnu_mtp_ra_sunrisedds_msg_Time.h"

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getFromJavaConverter
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getFromJavaConverter(JNIEnv * env, jclass cls)
{
  return 0;
}

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getToJavaConverter
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getToJavaConverter(JNIEnv * env, jclass cls)
{
  return 0;
}

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getTopicDescriptor
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getTopicDescriptor(JNIEnv * env, jclass cls)
{
  (void)env;
  (void)cls;
  return reinterpret_cast<jlong>(&builtin_interfaces_msg_Time_desc);
}

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_msg_Time
 * Method:    getDestructor
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_no_ntnu_mtp_ra_sunrisedds_msg_Time_getDestructor(JNIEnv * env, jclass cls)
{
  return 0;
}