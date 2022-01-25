/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class no_ntnu_mtp_ra_sunrisedds_SunriseDDS */

#ifndef _Included_no_ntnu_mtp_ra_sunrisedds_SunriseDDS
#define _Included_no_ntnu_mtp_ra_sunrisedds_SunriseDDS
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeCreateDomainParticipantHandle
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDomainParticipantHandle
  (JNIEnv *, jclass);

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeCreatePublisherHandle
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreatePublisherHandle
  (JNIEnv *, jclass, jint);

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeCreateSubscriberHandle
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateSubscriberHandle
  (JNIEnv *, jclass, jint);

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeCreateTopicHandle
 * Signature: (ILjava/lang/Class;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateTopicHandle
  (JNIEnv *, jclass, jint, jclass, jstring);

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeCreateDataWriterHandle
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDataWriterHandle
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeCreateDataReaderHandle
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeCreateDataReaderHandle
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeWrite
 * Signature: (ILno/ntnu/mtp/ra/sunrisedds/msg/MessageDefinition;)V
 */
JNIEXPORT void JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeWrite
  (JNIEnv *, jclass, jint, jobject);

/*
 * Class:     no_ntnu_mtp_ra_sunrisedds_SunriseDDS
 * Method:    nativeRead
 * Signature: (ILjava/lang/Class;)Lno/ntnu/mtp/ra/sunrisedds/msg/MessageDefinition;
 */
JNIEXPORT jobject JNICALL Java_no_ntnu_mtp_ra_sunrisedds_SunriseDDS_nativeRead
  (JNIEnv *, jclass, jint, jclass);

#ifdef __cplusplus
}
#endif
#endif
