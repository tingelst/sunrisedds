package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class DomainParticipant {

    private static final Logger logger = LoggerFactory.getLogger(DomainParticipant.class);

    private int handle;

    protected DomainParticipant(final int handle) {
        this.handle = handle;
    }

    public Publisher createPublisher() {
        int publisherHandle = SunriseDDS.nativeCreatePublisher(handle);
        // TODO(Lars): Check ret code and throw exception
        Publisher publisher = new Publisher(publisherHandle);
        return publisher;
    }

    public Subscriber createSubscriber() {
        int subscriberHandle = SunriseDDS.nativeCreateSubscriber(handle);
        Subscriber subscriber = new Subscriber(subscriberHandle);
        return subscriber;
    }

    public final int getHandle() {
        return this.handle;
    }

}
