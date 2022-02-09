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
import no.ntnu.mtp.ra.sunrisedds.domain.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.pub.DataWriter;
import no.ntnu.mtp.ra.sunrisedds.pub.Publisher;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;

import sensor_msgs.msg.JointState;

public class JointStatePublisher {
    private static final Logger logger = LoggerFactory.getLogger(JointStatePublisher.class);

    private DomainParticipant participant;
    private Publisher publisher;
    private Topic<JointState> topic;
    private DataWriter<JointState> writer;

    public JointStatePublisher(String topicName) throws DDSException {
        this.participant = SunriseDDS.createDomainParticipant();
        this.publisher = this.participant.createPublisher();
        this.topic = this.participant.createTopic(JointState.class, topicName);
        this.writer = this.publisher.createDataWriter(topic);
    }

    public void publish(JointState message) throws DDSException {
        this.writer.write(message);
    }

    public static void main(String[] args) {
        try {

            SunriseDDS.init();

            String topicName = "rt/joint_states";
            JointStatePublisher jointStatePublisher = new JointStatePublisher(topicName);

            JointState message = new JointState();

            message.getHeader().getStamp().setSec(1);
            message.getHeader().getStamp().setNanosec(2);
            message.getHeader().setFrameId("frameId");

            message.getName().add("joint_1");
            message.getName().add("joint_2");
            message.getName().add("joint_3");
            message.getName().add("joint_4");
            message.getName().add("joint_5");
            message.getName().add("joint_6");

            message.getPosition().add(1.0);
            message.getPosition().add(2.0);
            message.getPosition().add(3.0);
            message.getPosition().add(4.0);
            message.getPosition().add(5.0);
            message.getPosition().add(6.0);

            message.getVelocity().add(1.0);
            message.getVelocity().add(2.0);
            message.getVelocity().add(3.0);
            message.getVelocity().add(4.0);
            message.getVelocity().add(5.0);
            message.getVelocity().add(6.0);

            message.getEffort().add(1.0);
            message.getEffort().add(2.0);
            message.getEffort().add(3.0);
            message.getEffort().add(4.0);
            message.getEffort().add(5.0);
            message.getEffort().add(6.0);

            jointStatePublisher.publish(message);

            SunriseDDS.shutdown();

        } catch (DDSException e) {
            logger.error(e.getMessage());
            e.printStackTrace();
        }
    }
}
