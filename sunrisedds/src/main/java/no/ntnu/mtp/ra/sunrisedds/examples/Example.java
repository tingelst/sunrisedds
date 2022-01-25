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
import no.ntnu.mtp.ra.sunrisedds.msg.Header;
import no.ntnu.mtp.ra.sunrisedds.msg.Time;

public class Example {

    private static final Logger logger = LoggerFactory.getLogger(Example.class);

    public static void main(String[] args) {
        DomainParticipant participant = SunriseDDS.createDomainParticipant();
        Publisher publisher = participant.createPublisher();
        Subscriber subscriber = participant.createSubscriber();

        logger.info("Created subscriber with handle: " + String.valueOf(subscriber.getHandle()));

        Topic<Header> read_topic = participant.createTopic(Header.class, "rt/read_header");
        DataReader<Header> reader = subscriber.createDataReader(read_topic);

        Topic<Header> write_topic = participant.createTopic(Header.class, "rt/write_header");
        DataWriter<Header> writer = publisher.createDataWriter(write_topic);

        Header header = new Header();
        header.getStamp().setSec(1).setNanosec(2);
        header.setFrameId("Lars");

        writer.write(header);

        while (true) {
            Header message = reader.read();
            logger.info("sec: " + String.valueOf(message.getStamp().getSec()));
            logger.info("nanosec: " + String.valueOf(message.getStamp().getNanosec()));
            logger.info(message.getFrameId());
        }

    }

}
