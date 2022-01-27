// Copyright 2022 Norwegian University of Science and Technology.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
package no.ntnu.mtp.ra.sunrisedds.examples;

import java.util.ArrayList;
import java.util.List;

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
import no.ntnu.mtp.ra.sunrisedds.msg.JointState;
import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.msg.OnDataAvailableCallbackInterface;

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

        Topic<JointPosition> joint_position_write = participant.createTopic(JointPosition.class, "rt/write_position");
        DataWriter<JointPosition> joint_position_writer = publisher.createDataWriter(joint_position_write);

        Topic<JointPosition> read_position = participant.createTopic(JointPosition.class, "rt/read_position");
        DataReader<JointPosition> position_reader = subscriber.createDataReader(read_position);

        Topic<JointState> jointstate_topic = participant.createTopic(JointState.class, "rt/joint_states");
        DataWriter<JointState> jointstatewriter = publisher.createDataWriter(jointstate_topic);

        DataReader<JointState> jsreader = subscriber.createDataReader(jointstate_topic);

        jsreader.addOnDataAvailableCallback(new OnDataAvailableCallbackInterface() {
            @Override
            public void callback() {
                logger.info("from callback");

            }
        });

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

        double[] p = new double[] { 1.0, 2.0, 3.0 };
        double[] v = new double[] { 1.0, 2.0, 3.0 };
        double[] e = new double[] { 1.0, 2.0, 3.0 };

        String[] n = new String[] { "a", "b", "c" };

        List<String> name = new ArrayList<>();
        name.add("Lars");
        name.add("Tingelstad");

        List<Double> position_list = new ArrayList<>();
        position_list.add(1919.0);
        position_list.add(373737.0);

        JointState js = new JointState();
        js.setName(name);
        js.setPosition(position_list);

        jointstatewriter.write(js);

        // jointstatewriter
        // .write(new
        // JointState().setHeader(header).setName(n).setPosition(p).setVelocity(v).setEffort(e));
        // jointstatewriter.write(new JointState().setHeader(header));

        while (true) {
            JointState js2 = jsreader.read();
            logger.info(String.valueOf(js2.getPosition().get(0)));
            logger.info(js2.getName().get(0));
            logger.info(js2.getName().get(1));
        }

    }

}
