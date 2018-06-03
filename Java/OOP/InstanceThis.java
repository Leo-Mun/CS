package Exercise;

public class InstanceThis {
	String model;
	int speed;
	
	int age;
	
	void IncreasAge(int age){
		this.age += age;
	}
	
	
	InstanceThis(String model){ //Constructor
		this.model = model;
		
	}
	
	void setSpeed(int speed){ //필드 명이랑 인자 명이랑 같음 (변수 명이 같음) this는 클래스에 선언된 객체 내의 필드 값을 참조할 때 사용 
		this.speed = speed;
	}
	
	
	
	
	
}