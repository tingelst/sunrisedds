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
