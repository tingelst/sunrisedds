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
package no.ntnu.mtp.ra.sunrisedds.domain;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.core.DDSException;
import no.ntnu.mtp.ra.sunrisedds.core.Entity;
import no.ntnu.mtp.ra.sunrisedds.core.WaitSet;
import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.pub.Publisher;
import no.ntnu.mtp.ra.sunrisedds.sub.Subscriber;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;

public class DomainParticipant extends Entity {

    private static final Logger logger = LoggerFactory.getLogger(DomainParticipant.class);

    public DomainParticipant(final int handle) {
        super(handle);
    }

    public Publisher createPublisher() throws DDSException {
        int publisherHandle = SunriseDDS.nativeCreatePublisherHandle(this.getHandle());
        // TODO(Lars): Check ret code and throw exception
        Publisher publisher = new Publisher(publisherHandle);
        return publisher;
    }

    public Subscriber createSubscriber() throws DDSException {
        int subscriberHandle = SunriseDDS.nativeCreateSubscriberHandle(this.getHandle());
        Subscriber subscriber = new Subscriber(subscriberHandle);
        return subscriber;
    }

    public <T extends MessageDefinition> Topic<T> createTopic(final Class<T> messageType, final String topicName)
            throws DDSException {
        int topicHandle = SunriseDDS.nativeCreateTopicHandle(this.getHandle(), messageType, topicName);
        Topic<T> topic = new Topic<T>(topicHandle, messageType, topicName);
        return topic;
    }

    public WaitSet createWaitSet() throws DDSException {
        int waitSetHandle = SunriseDDS.nativeCreateWaitSetHandle(this.getHandle());
        WaitSet waitSet = new WaitSet(waitSetHandle);
        return waitSet;
    }

}
