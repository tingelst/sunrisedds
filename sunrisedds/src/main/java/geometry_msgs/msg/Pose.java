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

public class Pose implements MessageDefinition {
    private static final Logger logger = LoggerFactory.getLogger(Pose.class);

    static {
        try {
            JNIUtils.loadImplementation(Pose.class);
        } catch (final UnsatisfiedLinkError ule) {
            logger.error("Native code library failed to load.\n" + ule);
        }
    }

    private Point position = new Point();
    private Quaternion orientation = new Quaternion();

    public Point getPosition() {
        return position;
    }

    public Pose setPosition(Point position) {
        this.position = position;
        return this;
    }

    public Quaternion getOrientation() {
        return orientation;
    }

    public Pose setOrientation(Quaternion orientation) {
        this.orientation = orientation;
        return this;
    }

    public static native long getDestructor();

    public static native long getFromJavaConverter();

    public static native long getToJavaConverter();

    public static native long getTopicDescriptor();

    public long getDestructorInstance() {
        return Pose.getDestructor();
    }

    public long getFromJavaConverterInstance() {
        return Pose.getFromJavaConverter();
    }

    public long getToJavaConverterInstance() {
        return Pose.getToJavaConverter();
    }

    public long getTopicDescriptorInstance() {
        return Pose.getTopicDescriptor();
    }

}
