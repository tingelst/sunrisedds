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

public class JointQuantity implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(JointQuantity.class);

    static {
        try {
            JNIUtils.loadImplementation(JointQuantity.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
            System.exit(1);
        }
    }

    double a1;
    double a2;
    double a3;
    double a4;
    double a5;
    double a6;
    double a7;

    public double getA1() {
        return a1;
    }

    public JointQuantity setA1(final double a1) {
        this.a1 = a1;
        return this;
    }

    public double getA2() {
        return a2;
    }

    public JointQuantity setA2(final double a2) {
        this.a2 = a2;
        return this;
    }

    public double getA3() {
        return a3;
    }

    public JointQuantity setA3(final double a3) {
        this.a3 = a3;
        return this;
    }

    public double getA4() {
        return a4;
    }

    public JointQuantity setA4(final double a4) {
        this.a4 = a4;
        return this;
    }

    public double getA5() {
        return a5;
    }

    public JointQuantity setA5(final double a5) {
        this.a5 = a5;
        return this;
    }

    public double getA6() {
        return a6;
    }

    public JointQuantity setA6(final double a6) {
        this.a6 = a6;
        return this;
    }

    public double getA7() {
        return a7;
    }

    public JointQuantity setA7(final double a7) {
        this.a7 = a7;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return JointQuantity.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return JointQuantity.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return JointQuantity.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return JointQuantity.getDestructor();
    }

}
