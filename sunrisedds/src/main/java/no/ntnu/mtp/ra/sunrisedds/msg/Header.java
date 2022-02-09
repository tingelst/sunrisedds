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
package no.ntnu.mtp.ra.sunrisedds.msg;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class Header implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(Header.class);

    static {
        try {
            JNIUtils.loadImplementation(Header.class);
        } catch (UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    private Time stamp = new Time();
    private String frameId = "";

    public Time getStamp() {
        return stamp;
    }

    public Header setStamp(final Time stamp) {
        this.stamp = stamp;
        return this;
    }

    public String getFrameId() {
        return frameId;
    }

    public Header setFrameId(final String frameId) {
        this.frameId = frameId;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return Header.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return Header.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return Header.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return Header.getDestructor();
    }

}
