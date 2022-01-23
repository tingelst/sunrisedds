package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class DomainParticipant {

    private static final Logger logger = LoggerFactory.getLogger(DomainParticipant.class);

    private int handle;

    protected DomainParticipant(final int handle) {
        this.handle = handle;
    }

    public final int getHandle() {
        return this.handle;
    }

}