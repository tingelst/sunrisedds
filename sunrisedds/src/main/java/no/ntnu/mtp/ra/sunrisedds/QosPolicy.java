package no.ntnu.mtp.ra.sunrisedds;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class QosPolicy {
  private static final Logger logger = LoggerFactory.getLogger(QosPolicy.class);

    private long handle;

    protected QosPolicy(final long handle) {
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
