package no.ntnu.mtp.ra.sunrisedds.examples;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;

public class Example {

    private static final Logger logger = LoggerFactory.getLogger(Example.class);

    public static void main(String[] args) {
        DomainParticipant participant = SunriseDDS.createDomainParticipant();

    }

}
