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
package no.ntnu.mtp.ra.sunrisedds;

import java.net.ProtocolException;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.core.DDSException;
import no.ntnu.mtp.ra.sunrisedds.core.Duration;
import no.ntnu.mtp.ra.sunrisedds.core.policy.QosPolicy;
import no.ntnu.mtp.ra.sunrisedds.core.policy.Reliability;
import no.ntnu.mtp.ra.sunrisedds.domain.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.msg.OnDataAvailableCallbackInterface;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class SunriseDDS {

    private static final Logger logger = LoggerFactory.getLogger(SunriseDDS.class);

    static {
        try {
            JNIUtils.loadImplementation(SunriseDDS.class);
        } catch (UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    public static DomainParticipant createDomainParticipant() throws DDSException {
        int handle = nativeCreateDomainParticipantHandle();
        return new DomainParticipant(handle);
    }

    public static QosPolicy createQoSPolicy() {
        long handle = SunriseDDS.nativeCreateQosHandle();
        return new QosPolicy(handle);
    }

    public static Reliability createReliability() {
        return new Reliability(Reliability.Kind.RELIABLE, SunriseDDS.createDuration(100, TimeUnit.MILLISECONDS));
    }

    public static Duration createDuration(long duration, TimeUnit unit) {
        return new Duration(duration, unit);
    }

    public static native int nativeCreateDomainParticipantHandle() throws DDSException;

    public static native int nativeCreatePublisherHandle(int domainParticipantHandle) throws DDSException;

    public static native int nativeCreateSubscriberHandle(int domainParticipantHandle) throws DDSException;

    public static native <T extends MessageDefinition> int nativeCreateTopicHandle(int domainParticipantHandle,
            Class<T> messageType, String topicName) throws DDSException;

    public static native int nativeCreateDataWriterHandle(int participantOrPublisherHandle, int topicHandle)
            throws DDSException;

    public static native int nativeCreateDataReaderHandle(int participantOrSubscriberHandle, int topicHandle, long qosHandle)
            throws DDSException;

    public static native <T extends MessageDefinition> void nativeWrite(int writerHandle, T message)
            throws DDSException;

    public static native <T extends MessageDefinition> T nativeRead(int readerHandle, Class<T> messageClass)
            throws DDSException;

    public static native <T extends MessageDefinition> T nativeTake(int readerOrConditionHandle,
            Class<T> messageClass) throws DDSException;

    public static native void nativeAddOnDataAvailableCallback(int readerHandle,
            OnDataAvailableCallbackInterface callback);

    public static native int nativeCreateWaitSetHandle(int domainParticipantHandle) throws DDSException;

    public static native int nativeWaitSetAttach(int waitSetHandle, int entityHandle) throws DDSException;

    public static native int nativeWaitSetWait(int waitSetHandle, long timeout) throws DDSException;

    public static native int nativeCreateReadCondition(int readerHandle, int mask) throws DDSException;

    public static native long nativeCreateQosHandle();

    public static native void nativeDeleteQosHandle(long handle);

    public static native long nativeSetQosReliability(long qosHandle, int kind, long maxBlockingTime);


}
