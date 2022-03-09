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
package sunrisedds_interfaces.msg;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import geometry_msgs.msg.Pose;
import geometry_msgs.msg.Vector3;
import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class SmartServoLin implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(SmartServoLin.class);

    static {
        try {
            JNIUtils.loadImplementation(SmartServoLin.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
        }
    }

    public static final int SMART_SERVO_LIN_CARTESIAN_POSE = 0;
    public static final int SMART_SERVO_LIN_CARTESIAN_POSE_VELOCITY = 1;

    private int type = SmartServoLin.SMART_SERVO_LIN_CARTESIAN_POSE;
    private Pose cartesianPose = new Pose();
    private Vector3 translationalVelocity = new Vector3();

    public int getType() {
        return type;
    }

    public SmartServoLin setType(int type) {
        this.type = type;
        return this;
    }

    public Pose getCartesianPose() {
        return cartesianPose;
    }

    public SmartServoLin setCartesianPose(Pose cartesianPose) {
        this.cartesianPose = cartesianPose;
        return this;
    }

    public Vector3 getTranslationalVelocity() {
        return translationalVelocity;
    }

    public SmartServoLin setTranslationalVelocity(Vector3 translationalVelocity) {
        this.translationalVelocity = translationalVelocity;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return SmartServo.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return SmartServo.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return SmartServo.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return SmartServo.getDestructor();
    }

}
