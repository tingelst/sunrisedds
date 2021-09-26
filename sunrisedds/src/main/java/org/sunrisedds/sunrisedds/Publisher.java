package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;
import org.sunrisedds.sunrisedds.utils.JNIUtils;

public class Publisher {

    private static final Logger logger = LoggerFactory.getLogger(Publisher.class);

    static {
        try {
            JNIUtils.loadImplementation(Publisher.class);
        } catch (UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    private int handle;

    public Publisher(DomainParticipant domainParticipant) {
        this.handle = nativeCreatePublisherHandle(domainParticipant.getHandle());
    }

    public int getHandle() {
        return this.handle;
    }

    private static native int nativeCreatePublisherHandle(int domainParticipantHandle);

}
