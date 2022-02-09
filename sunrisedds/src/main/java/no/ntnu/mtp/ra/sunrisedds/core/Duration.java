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
package no.ntnu.mtp.ra.sunrisedds.core;

import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Duration {

    private static final Logger logger = LoggerFactory.getLogger(Duration.class);

    private static final long INFINITY = Long.MAX_VALUE;

    private long nanoseconds = 0;

    public Duration(long duration, TimeUnit unit) {
        this.nanoseconds = unit.toNanos(duration);
    }

    public Duration(long seconds, long nanoseconds) {
        this.nanoseconds = TimeUnit.SECONDS.toNanos(seconds) + nanoseconds;
    }

    public long getSeconds() {
        return TimeUnit.NANOSECONDS.toSeconds(this.nanoseconds);
    }

    public long getNanoseconds() {
        return this.nanoseconds;
    }

    public static void main(String[] args) {
        Duration d = new Duration(1, 1000000000);

        logger.info(String.valueOf(d.getSeconds()));
    }

    public static Duration infinity() {
        return new Duration(0, INFINITY);
    }


    public static Duration zero() {
        return new Duration(0, 0);
    }

}
