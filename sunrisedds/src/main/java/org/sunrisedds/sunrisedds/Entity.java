package org.sunrisedds.sunrisedds;

public abstract class Entity {

    protected final int handle;

    public Entity(int handle) {
        this.handle = handle;
    }

    public int getHandle() {
        return handle;
    }

}