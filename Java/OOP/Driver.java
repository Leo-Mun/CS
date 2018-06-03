package kr.ac.kookmin.cs.oop.inheritance;

public class Driver {
    public void drive(Car car) {
        car.run();
    }

    public static void main(String[] args) {
        Driver driver = new Driver();
        driver.drive(new Bus());
        driver.drive(new Taxi());
    }
}