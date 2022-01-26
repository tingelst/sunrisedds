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
import no.ntnu.mtp.ra.sunrisedds.msg.JointPosition;
import no.ntnu.mtp.ra.sunrisedds.msg.JointQuantity;
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

        Topic<JointQuantity> joint_quantity_read = participant.createTopic(JointQuantity.class, "rt/read_quantity");
        DataReader<JointQuantity> joint_quantity_reader = subscriber.createDataReader(joint_quantity_read);

        Topic<JointQuantity> joint_quantity_write = participant.createTopic(JointQuantity.class, "rt/write_quantity");
        DataWriter<JointQuantity> joint_quantity_writer = publisher.createDataWriter(joint_quantity_write);

        Topic<JointPosition> joint_position_write = participant.createTopic(JointPosition.class,"rt/write_position");
        DataWriter<JointPosition> joint_position_writer = publisher.createDataWriter(joint_position_write);

        Topic<JointPosition> read_position = participant.createTopic(JointPosition.class, "rt/read_position");
        DataReader<JointPosition> position_reader = subscriber.createDataReader(read_position);
        
        Header header = new Header();
        header.getStamp().setSec(1).setNanosec(2);
        header.setFrameId("Lars");

        writer.write(header);

        JointQuantity outmessage = new JointQuantity();
        outmessage.setA1(1.18181).setA2(0.3).setA3(3.).setA4(4.).setA5(52.).setA6(6.).setA7(7.);
        joint_quantity_writer.write(outmessage);


        JointPosition position = new JointPosition();
        position.getHeader().setFrameId("Lars22");
        position.getHeader().getStamp().setSec(99).setNanosec(22);
        position.setPosition(outmessage);
        joint_position_writer.write(position);

        while (true) {
            JointPosition msg = position_reader.read();
            // logger.info(msg.getHeader().getFrameId());
            // logger.info(String.valueOf(msg.getHeader().getStamp().getSec()));
            // logger.info(String.valueOf(msg.getPosition().getA7()));

        }

    }

}
