package no.ntnu.mtp.ra.sunrisedds;

public abstract class Entity {

    private final int handle;

    protected Entity(final int handle) {
        this.handle = handle;
    }

    public int getHandle() {
        return handle;
    }

}
