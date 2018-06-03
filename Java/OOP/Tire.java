package kr.ac.kookmin.cs.oop.inheritance;

public class Tire {
    private final int maxRotation;
    private String location;
    protected int accumulatedRotation;

    public Tire(String location, int maxRotation) {
        this.location = location;
        this.maxRotation = maxRotation;
    }

    public boolean roll() {
        ++accumulatedRotation;
        return checkTireLongevity();
    }

    protected boolean checkTireLongevity() {
        if (accumulatedRotation < maxRotation) {
            System.out.println(location + " rotation remaining : " + (maxRotation - accumulatedRotation));
            return true;
        } else {
            System.out.println(location + " has to be replaced");
            return false;
        }
    }
}
