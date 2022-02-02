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
package builtin_interfaces.msg;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class Time implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(Time.class);

    static {
        try {
            JNIUtils.loadImplementation(Time.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    int sec;
    int nanosec;

    public int getSec() {
        return sec;
    }

    public Time setSec(final int sec) {
        this.sec = sec;
        return this;
    }

    public int getNanosec() {
        return nanosec;
    }

    public Time setNanosec(final int nanosec) {
        this.nanosec = nanosec;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return Time.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return Time.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return Time.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return Time.getDestructor();
    }

}
