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

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

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

    protected static native int nativeCreateDomainParticipantHandle();

    protected static native int nativeCreatePublisherHandle(int domainParticipantHandle);

    protected static native int nativeCreateSubscriberHandle(int domainParticipantHandle);

    protected static native <T extends MessageDefinition> int nativeCreateTopicHandle(int domainParticipantHandle,
            Class<T> messageType, String topicName);

    protected static native int nativeCreateDataWriterHandle(int participantOrPublisherHandle, int topicHandle);

    protected static native int nativeCreateDataReaderHandle(int participantOrSubscriberHandle, int topicHandle);

    protected static native <T extends MessageDefinition> void nativeWrite(int writerHandle, T message);

    protected static native <T extends MessageDefinition> T nativeRead(int readerHandle, Class<T> messageClass);

    protected static native void nativeAddOnDataAvailableCallback(int readerHandle,
            OnDataAvailableCallbackInterface callback);

    protected static native int nativeCreateWaitSetHandle(int domainParticipantHandle);

    protected static native int nativeWaitSetAttach(int waitSetHandle, int entityHandle);

    protected static native int nativeWaitSetWait(int waitSetHandle, long timeout);
}
