package no.ntnu.mtp.ra.sunrisedds;

import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Duration {

    private static final Logger logger = LoggerFactory.getLogger(Duration.class);

    private static final long INFINITY = Long.MAX_VALUE;

    private long nanoseconds = 0;

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
