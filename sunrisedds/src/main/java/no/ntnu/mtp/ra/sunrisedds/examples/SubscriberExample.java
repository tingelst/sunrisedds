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
import no.ntnu.mtp.ra.sunrisedds.core.policy.QosPolicy;
import no.ntnu.mtp.ra.sunrisedds.domain.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.sub.DataReader;
import no.ntnu.mtp.ra.sunrisedds.sub.ReadCondition;
import no.ntnu.mtp.ra.sunrisedds.sub.Subscriber;
import no.ntnu.mtp.ra.sunrisedds.sub.Subscriber.DataState;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;
import sensor_msgs.msg.JointState;

public class SubscriberExample {

    private static final Logger logger = LoggerFactory.getLogger(SubscriberExample.class);

    public static void main(String[] args) {
        try {
            DomainParticipant participant = SunriseDDS.createDomainParticipant();
            Subscriber subscriber = participant.createSubscriber();
            Topic<JointState> topic = participant.createTopic(JointState.class, "rt/joint_states");


            QosPolicy qos = SunriseDDS.createQoSPolicy();
            qos.setReliability(SunriseDDS.createReliability());

            DataReader<JointState> reader = subscriber.createDataReader(topic, qos);

            DataState ds = subscriber.createDataState();
            ds.withAnyInstanceState();

            logger.info(String.valueOf(ds.getValue()));

            ReadCondition<JointState> readCondition = reader.createReadCondition(ds);

            WaitSet waitSet = participant.createWaitSet();
            // waitSet.attach(reader);
            waitSet.attach(readCondition);
            waitSet.waitForConditions(Duration.infinity());

            JointState message = null;
            int i = 0;
            while (message == null) {
                message = reader.take();
                i++;
            }
            logger.info("Took message");
            logger.info(String.valueOf(i));
            logger.info(message.getHeader().getFrameId());

        } catch (DDSException e) {
            logger.error(e.getMessage());
            e.printStackTrace();
        }
    }
}
