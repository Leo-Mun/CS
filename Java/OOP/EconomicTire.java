package kr.ac.kookmin.cs.oop.inheritance;

public class EconomicTire extends Tire {
    public EconomicTire(String location, int maxRotation) {
        super(location, maxRotation);
    }

    @Override
    public boolean roll() {
        ++accumulatedRotation;
        ++accumulatedRotation;
        return checkTireLongevity();
    }
}