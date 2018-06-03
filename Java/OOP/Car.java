package kr.ac.kookmin.cs.oop.inheritance;

import java.util.List;
import java.util.ArrayList;

public class Car {
	private List<Tire> tires;
//    Tire frontLeftTire = new Tire("FrontLeft", 6);
//    Tire frontRightTire = new Tire("FrontRight", 5);
//    Tire rearLeftTire = new PremiumTire("RearLeft", 4);
//    Tire rearRightTire = new PremiumTire("RearRight", 5); // polymorphism 의 장점
    // Tire[] tires = new Tire[4] 구현
    // run() 메소드 배열로 구현
    
//	public Car () {
//		Tire[] tires = new Tire[4];
//		tires[0] = new Tire("FrontLeft", 6);
//		tires[1] = new Tire("FrontRight", 5);
//		tires[2] = new PremiumTire("RearLeft", 4);
//		tires[3] = new PremiumTire("RearRight", 5);
//		
//	}
	
	public Car () {
		tires = new ArrayList<Tire>() ;
		tires.add(new Tire("FrontLeft", 6));
		tires.add(new Tire("FrontRight", 5));
		tires.add(new PremiumTire("RearLeft", 4));
		tires.add(new PremiumTire("RearRight", 5));
	}

	int run() {
		System.out.println("Four wheels are running");
		for (int tireChk = 0; tireChk < tires.size(); ++tireChk) {
			if (tires.get(tireChk).roll() == false) {
				stop();
				return tireChk + 1;
			}
		}
		
		return 0;
	}

//    int run() {
//        System.out.println("Four wheels are running");
//        if (frontLeftTire.roll() == false) {
//            stop();
//            return 1;
//        }
//        if (frontRightTire.roll() == false) {
//            stop();
//            return 2;
//        }
//        if (rearLeftTire.roll() == false) {
//            stop();
//            return 3;
//        }
//        if (rearRightTire.roll() == false) {
//            stop();
//            return 4;
//        }
//        return 0;
//    }

    void stop() {
        System.out.println("The car stops");
    }

    public static void main(String[] args) {
        Car car = new Car();
        for (int i = 1; i <= 5; i++) {
            int runStatus = car.run();
            System.out.println("Car status: " + runStatus);
            if (runStatus != 0) {
                break;
            }
            // System.out.println(car);
        }
    }
}