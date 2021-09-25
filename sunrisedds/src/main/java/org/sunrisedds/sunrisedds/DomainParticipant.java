package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;

public class DomainParticipant extends Entity {

    private static final Logger logger = LoggerFactory.getLogger(DomainParticipant.class);

    public DomainParticipant(int handle) {
        super(handle);
    }

    public Publisher createPublisher() {
        int handle = SunriseDDS.nativeCreatePublisher(this.handle);
        return new Publisher(handle);
    }

}
