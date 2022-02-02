package no.ntnu.mtp.ra.sunrisedds.sub;

public enum ViewState {

    NEW(4),
    NOT_NEW(8);

    private final int value;

    public int getValue() {
        return this.value;
    }

    private ViewState(final int value) {
        this.value = value;
    }

}
