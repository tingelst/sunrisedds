package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;

public class DomainParticipant {

    private static final Logger logger = LoggerFactory.getLogger(DomainParticipant.class);

    private int handle;

    protected DomainParticipant(final int handle) {
        this.handle = handle;
    }

    public Publisher createPublisher() {
        int publisherHandle = SunriseDDS.nativeCreatePublisherHandle(handle);
        // TODO(Lars): Check ret code and throw exception
        Publisher publisher = new Publisher(publisherHandle);
        return publisher;
    }

    public Subscriber createSubscriber() {
        int subscriberHandle = SunriseDDS.nativeCreateSubscriberHandle(handle);
        Subscriber subscriber = new Subscriber(subscriberHandle);
        return subscriber;
    }

    public <T extends MessageDefinition> Topic<T> createTopic(final Class<T> messageType, final String topicName) {
        int topicHandle = SunriseDDS.nativeCreateTopicHandle(handle, messageType, topicName);
        Topic<T> topic = new Topic<>(topicHandle, messageType, topicName);
        return topic;
    }

    public final int getHandle() {
        return this.handle;
    }

}
