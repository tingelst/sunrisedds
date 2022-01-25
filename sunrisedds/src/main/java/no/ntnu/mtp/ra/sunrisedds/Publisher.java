package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;

public class Publisher {

    private static final Logger logger = LoggerFactory.getLogger(Publisher.class);

    private int handle;

    protected Publisher(final int handle) {
        this.handle = handle;
    }

    public final int getHandle() {
        return this.handle;
    }

    public <T extends MessageDefinition> DataWriter<T> createDataWriter(Topic<T> topic) {
        int dataWriterHandle = SunriseDDS.nativeCreateDataWriterHandle(this.handle, topic.getHandle());
        return new DataWriter<T>(dataWriterHandle, topic);
    }

}
