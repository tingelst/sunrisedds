package org.sunrisedds.sunrisedds;

public class SunriseDDS {

    private SunriseDDS() {
    }

    public static native int nativeCreateDomainParticipant();

    public static void main(String[] args) {
        System.out.println("SunriseDDS");
    }
}