package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;

public class DataWriter<T extends MessageDefinition> {
  private static final Logger logger = LoggerFactory.getLogger(DataWriter.class);

  private int handle;

  private Topic<T> topic;

  protected DataWriter(final int handle, final Topic<T> topic) {
    this.handle = handle;
    this.topic = topic;
  }

  public void write(T message) {
    SunriseDDS.nativeWrite(handle, message);
  }

  public final int getHandle() {
    return this.handle;
  }

}
