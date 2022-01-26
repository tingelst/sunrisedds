package no.ntnu.mtp.ra.sunrisedds.msg;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class JointPosition implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(JointPosition.class);

    static {
        try {
            JNIUtils.loadImplementation(JointPosition.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    Header header = new Header();
    JointQuantity position = new JointQuantity();

    public Header getHeader() {
        return header;
    }

    public JointPosition setHeader(Header header) {
        this.header = header;
        return this;
    }

    public JointQuantity getPosition() {
        return position;
    }

    public JointPosition setPosition(JointQuantity position) {
        this.position = position;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return JointPosition.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return JointPosition.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return JointPosition.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return JointPosition.getDestructor();
    }

}
