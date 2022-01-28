package no.ntnu.mtp.ra.sunrisedds.examples;

import no.ntnu.mtp.ra.sunrisedds.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.WaitSet;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class WaitSetExample {

    private static final Logger logger = LoggerFactory.getLogger(WaitSetExample.class);

    public static void main(String[] args) {
        
        DomainParticipant participant = SunriseDDS.createDomainParticipant();
        WaitSet waitSet = participant.createWaitSet();

        logger.info(String.valueOf(waitSet.getHandle()));

    }

}
