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

public class WaitSet extends Entity {

    private static final Logger logger = LoggerFactory.getLogger(WaitSet.class);

    protected WaitSet(final int handle) {
        super(handle);
    }

    public void attach(Entity entity) throws DDSException {
        SunriseDDS.nativeWaitSetAttach(this.getHandle(), entity.getHandle());
    }

    public int wait(Duration reltimeout) throws DDSException {
        return SunriseDDS.nativeWaitSetWait(this.getHandle(), reltimeout.getNanoseconds());
    }

}
