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
import no.ntnu.mtp.ra.sunrisedds.msg.Header;
import no.ntnu.mtp.ra.sunrisedds.msg.JointState;
import no.ntnu.mtp.ra.sunrisedds.pub.DataWriter;
import no.ntnu.mtp.ra.sunrisedds.pub.Publisher;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;

public class PublisherExample {

    private static final Logger logger = LoggerFactory.getLogger(PublisherExample.class);

    public static void main(String[] args) {
        try {

            DomainParticipant participant = SunriseDDS.createDomainParticipant();
            Publisher publisher = participant.createPublisher();
            Topic<JointState> topic = participant.createTopic(JointState.class, "rt/joint_states");
            DataWriter<JointState> writer = publisher.createDataWriter(topic);
            WaitSet waitSet = participant.createWaitSet();

            logger.info("Publisher waiSet: " + String.valueOf(waitSet.getHandle()));

            waitSet.attach(writer);

            logger.info("Waiting for reader!");
            waitSet.waitForConditions(Duration.infinity());

            JointState message = new JointState();
            Header header = new Header();
            header.setFrameId("Lars");
            message.setHeader(header);

            writer.write(message);
            logger.info("Wrote message");

        } catch (DDSException e) {
            logger.error(e.getMessage());
            e.printStackTrace();
        }

    }

}
