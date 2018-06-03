package Exercise;

public class GetterSetterRunner {
	public static void main(String[] args){
		GetterSetter car = new GetterSetter();
		System.out.println(car.getSpeed());
		car.setSpeed(100);
		System.out.println(car.getSpeed());
		// System.out.println(car.speed)
		
	}
}
