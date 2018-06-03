package Exercise;

public class CarConstructor {
	String modelName; //Field
	String manufacturer;
	int modelYear;
	
	
	public CarConstructor(){ // Constructor1 선언 클래스명과 같은 이름을 메소드로 선언하면 됨
		this.modelName = "apollo";
		this.manufacturer = "KMU";
		this.modelYear = 2006;
	
	
	} 
		// Constructor는 클래스를 초기화를 해줘야 할 때 사용하면 됨
	                          
	
	public CarConstructor(String model){ // Constructor2 (Overloading)
		modelName = model;
		manufacturer = "KMU";
		modelYear = 0;
	}
	
	public CarConstructor(String model, String company, int year){ // Constructor3 (Overloading)
		modelName = model;
		manufacturer = company;
		modelYear = year;
	}
	
	public CarConstructor(String model, String company){ // Overloading의 특징 중요 (인자 전달)
		this(model, company, 0); // 다른 형태의 constructor을 호출 가능 (Constructor3 호출)
	}
	
	int getAge(int currentYear){
		int age = currentYear - this.modelYear;
		return age;
	}
	
	public static void main(String[] args){ // Garbage Collection 
		CarConstructor carFieldCheck = new CarConstructor(); // Constructor1 호출 (인자가 없음)
		System.out.println(carFieldCheck.modelName);
		System.out.println(carFieldCheck.manufacturer);
		System.out.println(carFieldCheck.modelYear);
		
		carFieldCheck = new CarConstructor("OOP", "leeky", 2014); //Constructor3 호출 (인자 3개) (Overloading)
		System.out.println(carFieldCheck.modelName);
		System.out.println(carFieldCheck.manufacturer);
		System.out.println(carFieldCheck.modelYear);
		
		carFieldCheck = new CarConstructor("OOP", "leeky", 2014);
		System.out.println(carFieldCheck.getAge(2016));
		
		carFieldCheck = new CarConstructor("car", "id", 2010);
		System.out.println(carFieldCheck.getAge(2016));
		
		
	
		
	}
	
}
