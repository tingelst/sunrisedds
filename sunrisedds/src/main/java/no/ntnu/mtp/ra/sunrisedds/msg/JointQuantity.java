package no.ntnu.mtp.ra.sunrisedds.msg;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class JointQuantity implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(JointQuantity.class);

    static {
        try {
            JNIUtils.loadImplementation(JointQuantity.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    float a1;
    float a2;
    float a3;
    float a4;
    float a5;
    float a6;
    float a7;

    public float getA1() {
        return a1;
    }

    public JointQuantity setA1(float a1) {
        this.a1 = a1;
        return this;
    }

    public float getA2() {
        return a2;
    }

    public JointQuantity setA2(float a2) {
        this.a2 = a2;
        return this;
    }

    public float getA3() {
        return a3;
    }

    public JointQuantity setA3(float a3) {
        this.a3 = a3;
        return this;
    }

    public float getA4() {
        return a4;
    }

    public JointQuantity setA4(float a4) {
        this.a4 = a4;
        return this;
    }

    public float getA5() {
        return a5;
    }

    public JointQuantity setA5(float a5) {
        this.a5 = a5;
        return this;
    }

    public float getA6() {
        return a6;
    }

    public JointQuantity setA6(float a6) {
        this.a6 = a6;
        return this;
    }

    public float getA7() {
        return a7;
    }

    public JointQuantity setA7(float a7) {
        this.a7 = a7;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return JointQuantity.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return JointQuantity.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return JointQuantity.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return JointQuantity.getDestructor();
    }

}
