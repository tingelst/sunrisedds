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

public class JointState implements MessageDefinition {
    private static final Logger logger = LoggerFactory.getLogger(JointState.class);

    static {
        try {
            JNIUtils.loadImplementation(JointState.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    private Header header;
    private String[] name;
    private double[] position;
    private double[] velocity;
    private double[] effort;

    public Header getHeader() {
        return header;
    }

    public JointState setHeader(final Header header) {
        this.header = header;
        return this;
    }

    public String[] getName() {
        return name;
    }

    public JointState setName(final String[] name) {
        this.name = name;
        return this;
    }

    public double[] getPosition() {
        return position;
    }

    public JointState setPosition(final double[] position) {
        this.position = position;
        return this;
    }

    public double[] getVelocity() {
        return velocity;
    }

    public JointState setVelocity(final double[] velocity) {
        this.velocity = velocity;
        return this;
    }

    public double[] getEffort() {
        return effort;
    }

    public JointState setEffort(final double[] effort) {
        this.effort = effort;
        return this;
    }

    public static native long getDestructor();

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public long getDestructorInstance() {
        return JointState.getDestructor();
    }

    public long getFromJavaConverterInstance() {
        return JointState.getFromJavaConverter();
    }

    public long getToJavaConverterInstance() {
        return JointState.getToJavaConverter();
    }

    public long getTopicDescriptorInstance() {
        return JointState.getTopicDescriptor();
    }

}
