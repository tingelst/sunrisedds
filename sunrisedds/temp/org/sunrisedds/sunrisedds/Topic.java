package org.sunrisedds.sunrisedds;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;

import no.mtp.ra.sunrisedds.utils.JNIUtils;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Topic<T extends MessageDefinition> {

  private static final Logger logger = LoggerFactory.getLogger(Topic.class);

  static {
    try {
      JNIUtils.loadImplementation(Topic.class);
    } catch (UnsatisfiedLinkError ule) {
      logger.error("Native code library failed to load.\n" + ule);
      System.exit(1);
    }
  }

  private int handle;

  private Class<T> messageType;

  private String topic;

  public Topic(final DomainParticipant domainParticipant, final Class<T> messageType, final String topic) {
    this.messageType = messageType;
    this.topic = topic;
    this.handle = nativeCreateTopicHandle(domainParticipant.getHandle(), messageType, topic);
  }

  public int getHandle() {
    return this.handle;
  }

  private static native <T extends MessageDefinition> int nativeCreateTopicHandle(int domainParticipantHandle,
      Class<T> messageType, String topic);

}
