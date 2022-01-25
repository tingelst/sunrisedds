package no.ntnu.mtp.ra.sunrisedds.examples;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.DataReader;
import no.ntnu.mtp.ra.sunrisedds.DataWriter;
import no.ntnu.mtp.ra.sunrisedds.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.Publisher;
import no.ntnu.mtp.ra.sunrisedds.Subscriber;
import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.Topic;
import no.ntnu.mtp.ra.sunrisedds.msg.Time;

public class Example {

    private static final Logger logger = LoggerFactory.getLogger(Example.class);

    public static void main(String[] args) {
        DomainParticipant participant = SunriseDDS.createDomainParticipant();
        Publisher publisher = participant.createPublisher();
        Subscriber subscriber = participant.createSubscriber();

        logger.info("Created subscriber with handle: " + String.valueOf(subscriber.getHandle()));

        Topic<Time> read_topic = participant.createTopic(Time.class, "rt/read_time");
        DataReader<Time> reader = subscriber.createDataReader(read_topic);

        Topic<Time> write_topic = participant.createTopic(Time.class, "rt/write_time");
        DataWriter<Time> writer = publisher.createDataWriter(write_topic);

        Time message = new Time();
        message.setSec(1);
        message.setNanosec(2);

        writer.write(message);

        // while (true) {}

        
    }

}
