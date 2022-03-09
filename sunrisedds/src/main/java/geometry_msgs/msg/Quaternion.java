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
package geometry_msgs.msg;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class Quaternion implements MessageDefinition {
    private static final Logger logger = LoggerFactory.getLogger(Quaternion.class);

    static {
        try {
            JNIUtils.loadImplementation(Quaternion.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
        }
    }

    private double x = 0.0;
    private double y = 0.0;
    private double z = 0.0;
    private double w = 1.0;

    public double getX() {
        return x;
    }

    public Quaternion setX(double x) {
        this.x = x;
        return this;
    }

    public double getY() {
        return y;
    }

    public Quaternion setY(double y) {
        this.y = y;
        return this;
    }

    public double getZ() {
        return z;
    }

    public Quaternion setZ(double z) {
        this.z = z;
        return this;
    }

    public double getW() {
        return w;
    }

    public Quaternion setW(double w) {
        this.w = w;
        return this;
    }

    public static native long getDestructor();

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public long getDestructorInstance() {
        return Quaternion.getDestructor();
    }

    public long getFromJavaConverterInstance() {
        return Quaternion.getFromJavaConverter();
    }

    public long getToJavaConverterInstance() {
        return Quaternion.getToJavaConverter();
    }

    public long getTopicDescriptorInstance() {
        return Quaternion.getTopicDescriptor();
    }

}
