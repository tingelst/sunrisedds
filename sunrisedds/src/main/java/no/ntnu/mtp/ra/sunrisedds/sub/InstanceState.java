package no.ntnu.mtp.ra.sunrisedds.sub;

public enum InstanceState {

    ALIVE(16),
    NOT_ALIVE_DISPOSED(32),
    NOT_ALIVE_NO_WRITERS(64);

    private final int value;

    public int getValue() {
        return this.value;
    }

    private InstanceState(int value) {
        this.value = value;
    }

}
