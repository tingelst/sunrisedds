package org.sunrisedds.sunrisedds.msg;

public class JointPosition {

    private double a1;
    private double a2;
    private double a3;
    private double a4;
    private double a5;
    private double a6;
    private double a7;

    public JointPosition(double a1, double a2, double a3, double a4, double a5, double a6, double a7) {
        this.a1 = a1;
        this.a2 = a2;
        this.a3 = a3;
        this.a4 = a4;
        this.a5 = a5;
        this.a6 = a6;
        this.a7 = a7;
    }

    public double getA1() {
        return this.a1;
    }

    public JointPosition setA1(double a1) {
        this.a1 = a1;
        return this;
    }

    public double getA2() {
        return this.a2;
    }

    public JointPosition setA2(double a2) {
        this.a2 = a2;
        return this;
    }

    public double getA3() {
        return this.a3;
    }

    public JointPosition setA3(double a3) {
        this.a3 = a3;
        return this;
    }

    public double getA4() {
        return this.a4;
    }

    public JointPosition setA4(double a4) {
        this.a4 = a4;
        return this;
    }

    public double getA5() {
        return this.a5;
    }

    public JointPosition setA6(double a6) {
        this.a6 = a6;
        return this;
    }

    public double getA7() {
        return this.a7;
    }

    public JointPosition setA7(double a7) {
        this.a7 = a7;
        return this;
    }

}
