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
package no.ntnu.mtp.ra.sunrisedds.sub;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.core.DDSException;
import no.ntnu.mtp.ra.sunrisedds.core.Entity;
import no.ntnu.mtp.ra.sunrisedds.core.policy.QosPolicy;
import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;

public class Subscriber extends Entity {

    private static final Logger logger = LoggerFactory.getLogger(Subscriber.class);

    public Subscriber(final int handle) {
        super(handle);
    }

    public <T extends MessageDefinition> DataReader<T> createDataReader(Topic<T> topic, QosPolicy qos)
            throws DDSException {
        int dataReaderHandle = SunriseDDS.nativeCreateDataReaderHandle(this.getHandle(), topic.getHandle(),
                qos.getHandle());
        qos.dispose();
        return new DataReader<T>(dataReaderHandle, topic);
    }

    public DataState createDataState() {
        return new DataState();
    }

    public class DataState {

        private Set<SampleState> sampleStates = new HashSet<SampleState>();
        private Set<ViewState> viewStates = new HashSet<ViewState>();
        private Set<InstanceState> instanceStates = new HashSet<InstanceState>();

        public DataState with(SampleState sampleState) {
            this.sampleStates.add(sampleState);
            return this;
        }

        public DataState with(ViewState viewState) {
            this.viewStates.add(viewState);
            return this;
        }

        public DataState with(InstanceState instanceState) {
            this.instanceStates.add(instanceState);
            return this;
        }

        public DataState withAnySampleState() {
            return this.with(SampleState.NOT_READ).with(SampleState.READ);
        }

        public DataState withAnyViewState() {
            return this.with(ViewState.NEW).with(ViewState.NOT_NEW);
        }

        public DataState withAnyInstanceState() {
            return this.with(InstanceState.ALIVE).with(InstanceState.NOT_ALIVE_DISPOSED)
                    .with(InstanceState.NOT_ALIVE_NO_WRITERS);
        }

        public DataState withNotAliveInstanceStates() {
            return this.with(InstanceState.NOT_ALIVE_DISPOSED).with(InstanceState.NOT_ALIVE_NO_WRITERS);
        }

        public DataState withAnyState() {
            return this.withAnySampleState().withAnyViewState().withAnyInstanceState();
        }

        public int getValue() {
            int value = 0;
            Iterator<SampleState> sampleStateIterator = sampleStates.iterator();
            while (sampleStateIterator.hasNext()) {
                value |= sampleStateIterator.next().getValue();
            }
            Iterator<ViewState> viewStateIterator = viewStates.iterator();
            while (viewStateIterator.hasNext()) {
                value |= viewStateIterator.next().getValue();
            }
            Iterator<InstanceState> instanceStateIterator = instanceStates.iterator();
            while (instanceStateIterator.hasNext()) {
                value |= instanceStateIterator.next().getValue();
            }
            return value;
        }

    }

}
