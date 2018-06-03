package kr.ac.kookmin.cs.oop.inheritance;

public class PremiumTire extends Tire {
    public PremiumTire(String location, int maxRotation) {
        super(location, maxRotation);
    }

    @Override
    public boolean roll() {
        if (Math.random() < 0.5) {
            ++accumulatedRotation;
        }
        return checkTireLongevity();
    }
}