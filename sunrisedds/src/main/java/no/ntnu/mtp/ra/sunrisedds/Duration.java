package no.ntnu.mtp.ra.sunrisedds;

import java.net.ProtocolException;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Duration {

    private static final Logger logger = LoggerFactory.getLogger(Duration.class);

    public static final long INFINITY = Long.MAX_VALUE;

    private long seconds = 0;
    private long nanoseconds = 0;

    public Duration(long seconds, long nanoseconds) {
        this.seconds = seconds;
        this.nanoseconds = nanoseconds;
    }

    public long getSeconds() {
        return this.seconds + TimeUnit.NANOSECONDS.toSeconds(this.nanoseconds);
    }

    public long getNanoseconds() {
        return TimeUnit.SECONDS.toNanos(this.seconds) + this.nanoseconds;
    }

    public static void main(String[] args) {
        Duration d = new Duration(1,1000000000);

        logger.info(String.valueOf(d.getSeconds()));
    }

}
