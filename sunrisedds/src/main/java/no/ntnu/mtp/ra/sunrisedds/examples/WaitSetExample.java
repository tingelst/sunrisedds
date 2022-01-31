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
package no.ntnu.mtp.ra.sunrisedds.examples;

import no.ntnu.mtp.ra.sunrisedds.DDSException;
import no.ntnu.mtp.ra.sunrisedds.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.WaitSet;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class WaitSetExample {

    private static final Logger logger = LoggerFactory.getLogger(WaitSetExample.class);

    public static void main(String[] args) {
        try {
            DomainParticipant participant = SunriseDDS.createDomainParticipant();
            WaitSet waitSet = participant.createWaitSet();
            logger.info(String.valueOf(waitSet.getHandle()));
        } catch (DDSException e) {
            logger.error(e.getMessage());
            e.printStackTrace();
        }
    }
}
