package no.ntnu.mtp.ra.sunrisedds.examples;

import no.ntnu.mtp.ra.sunrisedds.DDSException;
import no.ntnu.mtp.ra.sunrisedds.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;

public class ExceptionExample {

    public static void main(String[] args) {
        try {
            DomainParticipant p = SunriseDDS.createDomainParticipant();
        }
        catch (DDSException e) {
            System.out.println(e.getMessage());
        }
    }
    
}
