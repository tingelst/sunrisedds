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
import geometry_msgs.msg.Pose;

public class PosePubSub {

    private static final Logger logger = LoggerFactory.getLogger(PosePubSub.class);

    public static void main(String[] args) {
        try {

            DomainParticipant participant = SunriseDDS.createDomainParticipant();
            Publisher publisher = participant.createPublisher();
            Subscriber subscriber = participant.createSubscriber();
            Topic<Pose> topic = participant.createTopic(Pose.class, "rt/pose");
            DataWriter<Pose> writer = publisher.createDataWriter(topic);
            DataReader<Pose> reader = subscriber.createDataReader(topic);
            WaitSet waitSet = participant.createWaitSet();

            logger.info("Publisher waiSet: " + String.valueOf(waitSet.getHandle()));

            waitSet.attach(writer);

            logger.info("Waiting for reader!");
            waitSet.waitForConditions(Duration.infinity());

            Pose message = new Pose();

            writer.write(message);
            logger.info("Wrote message");

            Pose read_message = reader.read();
            logger.info("Point: ");
            logger.info("x: {}", read_message.getPosition().getX());
            logger.info("y: {}", read_message.getPosition().getY());
            logger.info("z: {}", read_message.getPosition().getZ());
            logger.info("Orientation: ");
            logger.info("x: {}", read_message.getOrientation().getX());
            logger.info("y: {}", read_message.getOrientation().getY());
            logger.info("z: {}", read_message.getOrientation().getZ());
            logger.info("w: {}", read_message.getOrientation().getW());

        } catch (DDSException e) {
            logger.error(e.getMessage());
            e.printStackTrace();
        }

    }

}
