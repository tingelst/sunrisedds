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

package no.ntnu.mtp.ra.sunrisedds;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Topic<T extends MessageDefinition> {

  private static final Logger logger = LoggerFactory.getLogger(Topic.class);

  private int handle;

  private Class<T> messageType;

  public final Class<T> getMessageType() {
    return messageType;
  }

  private String topicName;

  public final String getTopicName() {
    return topicName;
  }

  public Topic(final int handle, final Class<T> messageType, final String topicName) {
    this.handle = handle;
    this.messageType = messageType;
    this.topicName = topicName;
  }

  public final int getHandle() {
    return this.handle;
  }

}
