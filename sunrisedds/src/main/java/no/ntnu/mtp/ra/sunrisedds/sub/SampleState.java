package no.ntnu.mtp.ra.sunrisedds.sub;

public enum SampleState {

    READ(1),
    NOT_READ(2);

    private final int value;

    public int getValue() {
        return this.value;
    }

    private SampleState(final int value) {
        this.value = value;
    }

}
