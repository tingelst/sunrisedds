package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;

import no.mtp.ra.sunrisedds.utils.JNIUtils;

public class DataWriter<T extends MessageDefinition> {
  private static final Logger logger = LoggerFactory.getLogger(DataWriter.class);

  static {
    try {
      JNIUtils.loadImplementation(DataWriter.class);
    } catch (UnsatisfiedLinkError ule) {
      logger.error("Native code library failed to load.\n" + ule);
      System.exit(1);
    }
  }

  private int handle;

  private Topic<T> topic;

  public DataWriter(DomainParticipant domainParticipant, Topic<T> topic) {
    this(domainParticipant.getHandle(), topic);
  }

  public DataWriter(Publisher publisher, Topic<T> topic) {
    this(publisher.getHandle(), topic);
  }

  private DataWriter(int participantOrPublisherHandle, Topic<T> topic) {
    this.topic = topic;
    this.handle = nativeCreateDataWriterHandle(participantOrPublisherHandle, topic.getHandle());
  }

  private static native int nativeCreateDataWriterHandle(int participantOrPublisherHandle, int topicHandle);

}
