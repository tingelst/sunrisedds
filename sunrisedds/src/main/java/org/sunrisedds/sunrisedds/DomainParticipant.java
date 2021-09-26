package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;
import org.sunrisedds.sunrisedds.utils.JNIUtils;

public class DomainParticipant {

    private static final Logger logger = LoggerFactory.getLogger(DomainParticipant.class);

  static {
    try {
      JNIUtils.loadImplementation(NodeImpl.class);
    } catch (UnsatisfiedLinkError ule) {
      logger.error("Native code library failed to load.\n" + ule);
      System.exit(1);
    }
  }


    private static native int nativeCreateDomainParticipant();



}
