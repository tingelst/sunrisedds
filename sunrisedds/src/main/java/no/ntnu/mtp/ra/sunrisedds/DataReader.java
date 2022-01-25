package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;

public class DataReader<T extends MessageDefinition> {
  private static final Logger logger = LoggerFactory.getLogger(DataReader.class);

  private int handle;

  private Topic<T> topic;

  protected DataReader(final int handle, final Topic<T> topic) {
    this.handle = handle;
    this.topic = topic;
  }

  public T read() {
    T message = SunriseDDS.nativeRead(handle, topic.getMessageType());
    return message;
  }

  public final int getHandle() {
    return this.handle;
  }

}
