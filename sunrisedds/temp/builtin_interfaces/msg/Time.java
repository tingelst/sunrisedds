// generated from sunrisedds_generator/resource/msg.java.em
// with input from builtin_interfaces:msg/Time.idl
// generated code does not contain a copyright notice

package builtin_interfaces.msg;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;
import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;

import no.mtp.ra.sunrisedds.utils.JNIUtils;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;


public class Time implements MessageDefinition {

  private static final Logger logger = LoggerFactory.getLogger(Time.class);

  static {
    try {
      JNIUtils.loadImplementation(Time.class);
    } catch (UnsatisfiedLinkError ule) {
      logger.error("Native code library failed to load.\n" + ule);
      System.exit(1);
    }
  }

  public static native long getDestructor();
  public static native long getFromJavaConverter();
  public static native long getToJavaConverter();
  public static native long getTopicDescriptor();

  public long getDestructorInstance() {
    return Time.getDestructor();
  }

  public long getFromJavaConverterInstance() {
    return Time.getFromJavaConverter();
  }

  public long getToJavaConverterInstance() {
    return Time.getToJavaConverter();
  }

  public long getTopicDescriptorInstance() {
    return Time.getTopicDescriptor();
  }



  private int sec;

  public Time setSec(final int sec) {

    this.sec = sec;
    return this;
  }

  public int getSec() {
    return this.sec;
  }

  private int nanosec;

  public Time setNanosec(final int nanosec) {

    this.nanosec = nanosec;
    return this;
  }

  public int getNanosec() {
    return this.nanosec;
  }

  public int hashCode() {
    return new HashCodeBuilder(17, 37)
      .append(this.sec)
      .append(this.nanosec)
      .toHashCode();
  }

 public boolean equals(Object obj) {
   if (obj == null) { return false; }
   if (obj == this) { return true; }
   if (obj.getClass() != getClass()) {
     return false;
   }
   Time rhs = (Time) obj;
   return new EqualsBuilder()
                .append(this.sec, rhs.sec)
                .append(this.nanosec, rhs.nanosec)
                .isEquals();
  }
}
