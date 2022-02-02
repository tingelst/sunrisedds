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
