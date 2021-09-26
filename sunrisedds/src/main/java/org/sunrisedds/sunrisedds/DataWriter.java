package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;


public class DataWriter<T extends MessageDefinition> extends Entity {
    private static final Logger logger = LoggerFactory.getLogger(DataWriter.class);

    private Topic<T> topic;

    DataWriter(final int entityId, final Topic<T> topic) {
        super(entityId);
        this.topic = topic;
    }

    // public final void write(final T message) {
    //     SunriseDDS.nativeWrite(this.entityId, message);
    // }

}
