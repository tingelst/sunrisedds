package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;

public class Publisher extends Entity {

    private static final Logger logger = LoggerFactory.getLogger(Publisher.class);

    public Publisher(int handle) {
        super(handle);
    }

}
