package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class WaitSet extends Entity {

    private static final Logger logger = LoggerFactory.getLogger(WaitSet.class);

    protected WaitSet(final int handle) {
        super(handle);
    }

    public void attach(Entity entity) {
        SunriseDDS.nativeWaitSetAttach(this.getHandle(), entity.getHandle());
    }

    public void wait(int reltimeout) {
        SunriseDDS.nativeWaitSetWait(this.getHandle(), reltimeout);
    }

}
