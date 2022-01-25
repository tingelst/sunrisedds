package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;

public class Subscriber {

    private static final Logger logger = LoggerFactory.getLogger(Subscriber.class);

    private int handle;

    protected Subscriber(final int handle) {
        this.handle = handle;
    }

    public <T extends MessageDefinition> DataReader<T> createDataReader(Topic<T> topic) {
        int dataReaderHandle = SunriseDDS.nativeCreateDataReaderHandle(this.handle, topic.getHandle());
        return new DataReader<T>(dataReaderHandle, topic);
    }

    public final int getHandle() {
        return this.handle;
    }

}
