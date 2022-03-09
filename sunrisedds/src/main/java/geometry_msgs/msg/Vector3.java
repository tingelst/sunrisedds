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

public class Vector3 implements MessageDefinition {
    private static final Logger logger = LoggerFactory.getLogger(Vector3.class);

    static {
        try {
            JNIUtils.loadImplementation(Vector3.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
        }
    }

    private double x;
    private double y;
    private double z;


    public double getX() {
        return x;
    }

    public Vector3 setX(double x) {
        this.x = x;
        return this;
    }

    public double getY() {
        return y;
    }

    public Vector3 setY(double y) {
        this.y = y;
        return this;
    }

    public double getZ() {
        return z;
    }

    public Vector3 setZ(double z) {
        this.z = z;
        return this;
    }

    public static native long getDestructor();

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public long getDestructorInstance() {
        return Vector3.getDestructor();
    }

    public long getFromJavaConverterInstance() {
        return Vector3.getFromJavaConverter();
    }

    public long getToJavaConverterInstance() {
        return Vector3.getToJavaConverter();
    }

    public long getTopicDescriptorInstance() {
        return Vector3.getTopicDescriptor();
    }
    
}
