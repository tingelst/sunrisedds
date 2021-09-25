package org.sunrisedds.sunrisedds;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;
import org.sunrisedds.sunrisedds.utils.JNIUtils;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Topic<T extends MessageDefinition> extends Entity {

    private static final Logger logger = LoggerFactory.getLogger(Topic.class);

    private final Class<T> messageType;

    private final String topic;

    public Topic(int entityId, final Class<T> messageType, final String topic) {
        super(entityId);
        this.messageType = messageType;
        this.topic = topic;
    }

}
