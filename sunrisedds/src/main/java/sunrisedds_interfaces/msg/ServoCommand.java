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

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.utils.JNIUtils;
import std_msgs.msg.Header;

public class ServoCommand implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(ServoCommand.class);

    static {
        try {
            JNIUtils.loadImplementation(ServoCommand.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
        }
    }

    public static final int SMART_SERVO = 0;
    public static final int DIRECT_SERVO = 1;
    public static final int SMART_SERVO_LIN = 2;

    private Header header = new Header();
    private int type = ServoCommand.SMART_SERVO;
    private SmartServo smartServo = new SmartServo();
    private DirectServo directServo = new DirectServo();
    private SmartServoLin smartServoLin = new SmartServoLin();

    public Header getHeader() {
        return header;
    }

    public ServoCommand setHeader(Header header) {
        this.header = header;
        return this;
    }

    public int getType() {
        return type;
    }

    public ServoCommand setType(int type) {
        this.type = type;
        return this;
    }

    public SmartServo getSmartServo() {
        return smartServo;
    }

    public ServoCommand setSmartServo(SmartServo smartServo) {
        this.smartServo = smartServo;
        return this;
    }

    public DirectServo getDirectServo() {
        return directServo;
    }

    public ServoCommand setDirectServo(DirectServo directServo) {
        this.directServo = directServo;
        return this;
    }

    public SmartServoLin getSmartServoLin() {
        return smartServoLin;
    }

    public ServoCommand setSmartServoLin(SmartServoLin smartServoLin) {
        this.smartServoLin = smartServoLin;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return ServoCommand.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return ServoCommand.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return ServoCommand.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return ServoCommand.getDestructor();
    }

}
