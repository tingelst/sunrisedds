// generated from sunrisedds_generator/resource/msg.java.em
// with input from std_msgs:msg/Header.idl
// generated code does not contain a copyright notice

package std_msgs.msg;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;
import org.sunrisedds.sunrisedds.utils.JNIUtils;
import org.sunrisedds.sunrisedds.interfaces.MessageDefinition;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

// Member 'stamp'
import builtin_interfaces.msg.Time;

public class Header implements MessageDefinition {

  private static final Logger logger = LoggerFactory.getLogger(Header.class);

  static {
    try {
      JNIUtils.loadImplementation(Header.class);
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
    return Header.getDestructor();
  }

  public long getFromJavaConverterInstance() {
    return Header.getFromJavaConverter();
  }

  public long getToJavaConverterInstance() {
    return Header.getToJavaConverter();
  }

  public long getTopicDescriptorInstance() {
    return Header.getTopicDescriptor();
  }



  private builtin_interfaces.msg.Time stamp = new builtin_interfaces.msg.Time();

  public Header setStamp(final builtin_interfaces.msg.Time stamp) {

    this.stamp = stamp;
    return this;
  }

  public builtin_interfaces.msg.Time getStamp() {
    return this.stamp;
  }

  private java.lang.String frame_id = "";

  public Header setFrameId(final java.lang.String frame_id) {

    this.frame_id = frame_id;
    return this;
  }

  public java.lang.String getFrameId() {
    return this.frame_id;
  }

  public int hashCode() {
    return new HashCodeBuilder(17, 37)
      .append(this.stamp)
      .append(this.frame_id)
      .toHashCode();
  }

 public boolean equals(Object obj) {
   if (obj == null) { return false; }
   if (obj == this) { return true; }
   if (obj.getClass() != getClass()) {
     return false;
   }
   Header rhs = (Header) obj;
   return new EqualsBuilder()
                .append(this.stamp, rhs.stamp)
                .append(this.frame_id, rhs.frame_id)
                .isEquals();
  }
}
