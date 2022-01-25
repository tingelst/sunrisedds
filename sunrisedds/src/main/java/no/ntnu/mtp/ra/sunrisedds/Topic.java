package no.ntnu.mtp.ra.sunrisedds;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Topic<T extends MessageDefinition> {

  private static final Logger logger = LoggerFactory.getLogger(Topic.class);

  private int handle;

  private Class<T> messageType;

  public final Class<T> getMessageType() {
    return messageType;
  }

  private String topicName;

  public final String getTopicName() {
    return topicName;
  }

  public Topic(final int handle, final Class<T> messageType, final String topicName) {
    this.handle = handle;
    this.messageType = messageType;
    this.topicName = topicName;
  }

  public final int getHandle() {
    return this.handle;
  }

}
