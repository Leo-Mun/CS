package kr.ac.kookmin.cs.oop.inheritance;

public class SmartWatch extends SmartPhone {
	public SmartWatch(String model, String color, String appMarket) { // 부모 클래스에 Constructor 가 있는 경우 무조건 부모클래스의 Constructor을 호출(super 사용)
		super(model, color, appMarket);								  // 부모 클래스의 객체를 자식 클래스로 또 만들어 주는 의미를 내포
	
	}
	
	@Override
	public void runBrowser() {
		// super.runBrowser(); // super 을 붙이면 부모 클래스의 인스턴스를 호출함
		System.out.println("Staring a Samrt Watch Browser");
		System.out.println("Executing Smart Watch Browser");
		// super.runBrowser(); // 본인 클래스 참조는 this
		
	}
	
	public static void main(String[] args) {
		SmartWatch smartWatch = new SmartWatch("apple", "Yellow", "AppStore");
		smartWatch.powerOn();
		smartWatch.runBrowser();
		
	}
}
