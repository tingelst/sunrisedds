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
import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;

public class SmartServo implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(SmartServo.class);

    static {
        try {
            JNIUtils.loadImplementation(SmartServo.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
        }
    }

    public static final int SMART_SERVO_JOINT_POSITION = 0;
    public static final int SMART_SERVO_JOINT_POSITION_VELOCITY = 1;
    public static final int SMART_SERVO_CARTESIAN_POSE = 2;

    private int type = SmartServo.SMART_SERVO_JOINT_POSITION;
    private JointQuantity jointPosition = new JointQuantity();
    private JointQuantity jointVelocity = new JointQuantity();
    private Pose cartesianPose = new Pose();
    private JointQuantity jointVelocityRel = new JointQuantity();
    private JointQuantity jointAccelerationRel = new JointQuantity();

    public int getType() {
        return type;
    }

    public SmartServo setType(int type) {
        this.type = type;
        return this;
    }

    public JointQuantity getJointPosition() {
        return jointPosition;
    }

    public SmartServo setJointPosition(JointQuantity jointPosition) {
        this.jointPosition = jointPosition;
        return this;
    }

    public JointQuantity getJointVelocity() {
        return jointVelocity;
    }

    public SmartServo setJointVelocity(JointQuantity jointVelocity) {
        this.jointVelocity = jointVelocity;
        return this;
    }

    public Pose getCartesianPose() {
        return cartesianPose;
    }

    public SmartServo setCartesianPose(Pose cartesianPose) {
        this.cartesianPose = cartesianPose;
        return this;
    }

    public JointQuantity getJointVelocityRel() {
        return jointVelocityRel;
    }

    public SmartServo setJointVelocityRel(JointQuantity jointVelocityRel) {
        this.jointVelocityRel = jointVelocityRel;
        return this;
    }

    public JointQuantity getJointAccelerationRel() {
        return jointAccelerationRel;
    }

    public SmartServo setJointAccelerationRel(JointQuantity jointAccelerationRel) {
        this.jointAccelerationRel = jointAccelerationRel;
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
