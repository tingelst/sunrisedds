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

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.msg.MessageDefinition;
import no.ntnu.mtp.ra.sunrisedds.msg.OnDataAvailableCallbackInterface;

public class DataReader<T extends MessageDefinition> extends Entity {
  private static final Logger logger = LoggerFactory.getLogger(DataReader.class);

  private Topic<T> topic;

  private boolean dataAvailable = false;

  protected DataReader(final int handle, final Topic<T> topic) {
    super(handle);
    this.topic = topic;
  }

  public T read() {
    T message = SunriseDDS.nativeRead(this.getHandle(), topic.getMessageType());
    return message;
  }

  public void addOnDataAvailableCallback(OnDataAvailableCallbackInterface callback) {
    SunriseDDS.nativeAddOnDataAvailableCallback(this.getHandle(), callback);
  }

}
