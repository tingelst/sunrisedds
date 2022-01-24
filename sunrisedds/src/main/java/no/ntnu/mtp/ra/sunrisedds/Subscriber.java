package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Subscriber {

    private static final Logger logger = LoggerFactory.getLogger(Subscriber.class);

    private int handle;

    protected Subscriber(final int handle) {
        this.handle = handle;
    }

    public final int getHandle() {
        return this.handle;
    }

}
