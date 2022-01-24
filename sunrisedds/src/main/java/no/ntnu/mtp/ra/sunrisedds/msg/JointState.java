package no.ntnu.mtp.ra.sunrisedds.msg;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class JointState implements MessageDefinition {
    private static final Logger logger = LoggerFactory.getLogger(JointState.class);

    static {
        try {
            JNIUtils.loadImplementation(JointState.class);
        } catch (UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    private Header header;
    private String[] name;
    private double[] position;
    private double[] velocity;
    private double[] effort;

    public JointState() {
    }

    public Header getHeader() {
        return header;
    }

    public void setHeader(Header header) {
        this.header = header;
    }

    public String[] getName() {
        return name;
    }

    public void setName(String[] name) {
        this.name = name;
    }

    public double[] getPosition() {
        return position;
    }

    public void setPosition(double[] position) {
        this.position = position;
    }

    public double[] getVelocity() {
        return velocity;
    }

    public void setVelocity(double[] velocity) {
        this.velocity = velocity;
    }

    public double[] getEffort() {
        return effort;
    }

    public void setEffort(double[] effort) {
        this.effort = effort;
    }

    public static native long getDestructor();

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public long getDestructorInstance() {
        return JointState.getDestructor();
    }

    public long getFromJavaConverterInstance() {
        return JointState.getFromJavaConverter();
    }

    public long getToJavaConverterInstance() {
        return JointState.getToJavaConverter();
    }

    public long getTopicDescriptorInstance() {
        return JointState.getTopicDescriptor();
    }

    public static native long convertFromJava(JointState msg);

}
