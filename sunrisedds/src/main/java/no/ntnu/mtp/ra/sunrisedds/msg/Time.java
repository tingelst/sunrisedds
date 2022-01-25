package no.ntnu.mtp.ra.sunrisedds.msg;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

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

    int sec;
    int nanosec;

    public int getSec() {
        return sec;
    }

    public Time setSec(int sec) {
        this.sec = sec;
        return this;
    }

    public int getNanosec() {
        return nanosec;
    }

    public Time setNanosec(int nanosec) {
        this.nanosec = nanosec;
        return this;
    }


    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return Time.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return Time.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return Time.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return Time.getDestructor();
    }

}
