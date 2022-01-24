package no.ntnu.mtp.ra.sunrisedds.msg;

public class Header {

    private Time stamp = null;
    private String frameId = "";

    public Header(Time stamp, String frameId) {
        this.stamp = stamp;
        this.frameId = frameId;
    }

    public Time getStamp() {
        return stamp;
    }

    public void setStamp(Time stamp) {
        this.stamp = stamp;
    }

    public String getFrameId() {
        return frameId;
    }

    public void setFrameId(String frameId) {
        this.frameId = frameId;
    }

}
