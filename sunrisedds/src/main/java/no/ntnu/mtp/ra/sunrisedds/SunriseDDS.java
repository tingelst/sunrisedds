package no.ntnu.mtp.ra.sunrisedds;

import java.net.ProtocolException;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class SunriseDDS {

    private static final Logger logger = LoggerFactory.getLogger(SunriseDDS.class);

    static {
        try {
            JNIUtils.loadImplementation(SunriseDDS.class);
        } catch (UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    public static DomainParticipant createDomainParticipant() {
        int handle = nativeCreateDomainParticipantHandle();
        return new DomainParticipant(handle);
    }

    protected static native int nativeCreateDomainParticipantHandle();

    protected static native int nativeCreatePublisherHandle(int domainParticipantHandle);

    protected static native int nativeCreateSubscriberHandle(int domainParticipantHandle);

    protected static native <T extends MessageDefinition> int nativeCreateTopicHandle(int domainParticipantHandle,
            Class<T> messageType, String topicName);

    protected static native int nativeCreateDataWriterHandle(int participantOrPublisherHandle, int topicHandle);

    protected static native int nativeCreateDataReaderHandle(int participantOrSubscriberHandle, int topicHandle);

}
