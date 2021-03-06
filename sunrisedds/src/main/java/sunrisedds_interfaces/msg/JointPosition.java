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

public class JointPosition implements MessageDefinition {

    private static final Logger logger = LoggerFactory.getLogger(JointPosition.class);

    static {
        try {
            JNIUtils.loadImplementation(JointPosition.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
        }
    }

    Header header = new Header();
    JointQuantity position = new JointQuantity();

    public Header getHeader() {
        return header;
    }

    public JointPosition setHeader(Header header) {
        this.header = header;
        return this;
    }

    public JointQuantity getPosition() {
        return position;
    }

    public JointPosition setPosition(JointQuantity position) {
        this.position = position;
        return this;
    }

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public static native long getDestructor();

    @Override
    public long getFromJavaConverterInstance() {
        return JointPosition.getFromJavaConverter();
    }

    @Override
    public long getToJavaConverterInstance() {
        return JointPosition.getToJavaConverter();
    }

    @Override
    public long getTopicDescriptorInstance() {
        return JointPosition.getTopicDescriptor();
    }

    @Override
    public long getDestructorInstance() {
        return JointPosition.getDestructor();
    }

}
