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

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.core.DDSException;
import no.ntnu.mtp.ra.sunrisedds.core.Duration;
import no.ntnu.mtp.ra.sunrisedds.core.WaitSet;
import no.ntnu.mtp.ra.sunrisedds.domain.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.pub.DataWriter;
import no.ntnu.mtp.ra.sunrisedds.pub.Publisher;
import no.ntnu.mtp.ra.sunrisedds.sub.DataReader;
import no.ntnu.mtp.ra.sunrisedds.sub.Subscriber;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;
import sunrisedds_interfaces.msg.DirectServo;
import sunrisedds_interfaces.msg.ServoCommand;

public class ServoCommandPubSub {

    private static final Logger logger = LoggerFactory.getLogger(ServoCommandPubSub.class);

    public static void main(String[] args) {
        try {

            DomainParticipant participant = SunriseDDS.createDomainParticipant();
            Publisher publisher = participant.createPublisher();
            Subscriber subscriber = participant.createSubscriber();
            Topic<ServoCommand> topic = participant.createTopic(ServoCommand.class, "rt/servocommand");
            DataWriter<ServoCommand> writer = publisher.createDataWriter(topic);
            DataReader<ServoCommand> reader = subscriber.createDataReader(topic);
            WaitSet waitSet = participant.createWaitSet();

            logger.info("Publisher waiSet: " + String.valueOf(waitSet.getHandle()));

            waitSet.attach(writer);

            logger.info("Waiting for reader!");
            waitSet.waitForConditions(Duration.infinity());

            ServoCommand message = new ServoCommand();

            message.setType(ServoCommand.DIRECT_SERVO);
            message.getDirectServo().setType(DirectServo.DIRECT_SERVO_JOINT_POSITION);
            message.getDirectServo().getJointPosition()
                    .setA1(1.0)
                    .setA2(1.0)
                    .setA3(1.0)
                    .setA4(1.0)
                    .setA5(1.0)
                    .setA6(1.0)
                    .setA7(1.0);
            message.getDirectServo().getJointVelocityRel()
                    .setA1(1.0)
                    .setA2(1.0)
                    .setA3(1.0)
                    .setA4(1.0)
                    .setA5(1.0)
                    .setA6(1.0)
                    .setA7(1.0);

            writer.write(message);
            logger.info("Wrote message");

            ServoCommand read_message = reader.read();

        } catch (DDSException e) {
            logger.error(e.getMessage());
            e.printStackTrace();
        }

    }

}
