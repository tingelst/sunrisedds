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

import no.ntnu.mtp.ra.sunrisedds.core.Duration;

public class Reliability {

    private final Kind kind;
    private final Duration maxBlockingTime;

    public Reliability(final Kind kind, final Duration maxBlockingTime) {
        this.kind = kind;
        this.maxBlockingTime = maxBlockingTime;
    }

    public Kind getKind() {
        return kind;
    }

    public Duration getMaxBlockingTime() {
        return maxBlockingTime;
    }

    public enum Kind {
        BEST_EFFORT(0), RELIABLE(1);

        private final int value;

        private Kind(final int value) {
            this.value = value;
        }

        public int getValue() {
            return this.value;
        }

    }
}
