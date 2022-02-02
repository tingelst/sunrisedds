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
package no.ntnu.mtp.ra.sunrisedds.core.policy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;

public class QosPolicy {
  private static final Logger logger = LoggerFactory.getLogger(QosPolicy.class);

    private long handle;

    public QosPolicy(final long handle) {
        this.handle = handle;
    }

    public QosPolicy setReliability(Reliability reliability) {
        this.handle = SunriseDDS.nativeSetQosReliability(this.handle, reliability.getKind().getValue(),
                reliability.getMaxBlockingTime().getNanoseconds());
        return this;
    }

    public final void dispose() {
        SunriseDDS.nativeDeleteQosHandle(this.handle);
        this.handle = 0;
    }

    public final long getHandle() {
        return this.handle;
    }

}
