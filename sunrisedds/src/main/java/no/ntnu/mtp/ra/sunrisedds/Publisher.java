package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Publisher {

    private static final Logger logger = LoggerFactory.getLogger(Publisher.class);

    private int handle;

    protected Publisher(final int handle) {
        this.handle = handle;
    }

    public final int getHandle() {
        return this.handle;
    }

}
