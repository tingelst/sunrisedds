package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;

import no.mtp.ra.sunrisedds.utils.JNIUtils;

public class DomainParticipant {

  private static final Logger logger = LoggerFactory.getLogger(DomainParticipant.class);

  static {
    try {
      JNIUtils.loadImplementation(DomainParticipant.class);
    } catch (UnsatisfiedLinkError ule) {
      logger.error("Native code library failed to load.\n" + ule);
      System.exit(1);
    }
  }

  private int handle;

  public DomainParticipant() {
    this.handle = nativeCreateDomainParticipant();
  }

  public Publisher createPublisher() {
    return new Publisher(this);
  }

  public int getHandle() {
    return this.handle;
  }

  private static native int nativeCreateDomainParticipant();

}
