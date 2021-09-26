package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class SunriseDDS {

    private static final Logger logger = LoggerFactory.getLogger(SunriseDDS.class);

    static {
        try {
            String libraryName = "sunrisedds";
            logger.info("Loading native code library: " + libraryName);
            System.loadLibrary(libraryName);
        } catch (UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    private SunriseDDS() {
    }

    public static DomainParticipant createDomainParticipant() {
        int handle = nativeCreateDomainParticipant();
        // return new DomainParticipant(handle);
    }

    public static native int nativeCreateDomainParticipant();

    public static native int nativeCreateSubscriber(int participantHandle);

    public static native int nativeCreatePublisher(int participantHandle);

    public static native int nativeCreateJointPositionReader(int participantHandle, int subscriberHandle, String topic,
            OnDataAvailableCallbackInterface callback);

    public static native void nativeJointPositionReaderRead(int readerHandle);

    public static void main(String[] args) {
        int participantHandle = nativeCreateDomainParticipant();
        logger.info("{}", participantHandle);

        int subscriberHandle = nativeCreateSubscriber(participantHandle);
        logger.info("{}", subscriberHandle);

        OnJointPositionDataAvailableCallback callback = new OnJointPositionDataAvailableCallback();

        int readerHandle = nativeCreateJointPositionReader(participantHandle, subscriberHandle, "rt/joint_position",
                callback);
        logger.info("reader: {}", readerHandle);

        while (true) {

        }

    }
}