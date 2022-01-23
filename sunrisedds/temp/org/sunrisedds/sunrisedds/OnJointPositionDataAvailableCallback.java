package org.sunrisedds.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class OnJointPositionDataAvailableCallback implements OnDataAvailableCallbackInterface {

    private static Logger logger = LoggerFactory.getLogger(OnJointPositionDataAvailableCallback.class);

    public void callback(float a1) {
        logger.info("{}", a1);
    }

}
