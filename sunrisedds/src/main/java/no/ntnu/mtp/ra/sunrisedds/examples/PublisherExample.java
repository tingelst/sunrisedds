package no.ntnu.mtp.ra.sunrisedds.examples;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.DataWriter;
import no.ntnu.mtp.ra.sunrisedds.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.Publisher;
import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.Topic;
import no.ntnu.mtp.ra.sunrisedds.WaitSet;
import no.ntnu.mtp.ra.sunrisedds.msg.JointState;

public class PublisherExample {

    private static final Logger logger = LoggerFactory.getLogger(PublisherExample.class);

    public static void main(String[] args) {
        DomainParticipant participant = SunriseDDS.createDomainParticipant();
        Publisher publisher = participant.createPublisher();
        Topic<JointState> topic = participant.createTopic(JointState.class, "rt/joint_states");
        DataWriter<JointState> writer = publisher.createDataWriter(topic);
        WaitSet waitSet = participant.createWaitSet();

        waitSet.attach(writer);

        logger.info("Waiting for reader!");
        int FOREVER = Integer.MAX_VALUE;
        waitSet.wait(FOREVER);

        JointState message = new JointState();

        writer.write(message);
        logger.info("Wrote message");

    }

}
