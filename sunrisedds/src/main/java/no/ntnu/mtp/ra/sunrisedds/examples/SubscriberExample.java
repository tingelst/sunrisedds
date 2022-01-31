package no.ntnu.mtp.ra.sunrisedds.examples;

import java.io.Reader;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.DDSException;
import no.ntnu.mtp.ra.sunrisedds.DataReader;
import no.ntnu.mtp.ra.sunrisedds.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.Duration;
import no.ntnu.mtp.ra.sunrisedds.Subscriber;
import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.Topic;
import no.ntnu.mtp.ra.sunrisedds.WaitSet;
import no.ntnu.mtp.ra.sunrisedds.msg.JointState;

public class SubscriberExample {

    private static final Logger logger = LoggerFactory.getLogger(SubscriberExample.class);

    public static void main(String[] args) {
        try {
            DomainParticipant participant = SunriseDDS.createDomainParticipant();
            Subscriber subscriber = participant.createSubscriber();
            Topic<JointState> topic = participant.createTopic(JointState.class, "rt/joint_states");
            DataReader<JointState> reader = subscriber.createDataReader(topic);
            WaitSet waitSet = participant.createWaitSet();

            waitSet.attach(reader);

            logger.info("Waiting for writer!");
            waitSet.wait(Duration.infinity());

            JointState message = new JointState();

            reader.read();
            logger.info("Read message");

        } catch (DDSException e) {
            logger.error(e.getMessage());
            e.printStackTrace();
        }
    }
}
