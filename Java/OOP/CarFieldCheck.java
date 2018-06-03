package Exercise;

public class CarFieldCheck {
	
	String modelName = "apollo";
	String manufacturer = "KMU";
	int modelYear = 2006;
	
	
	
	
	
	
	
	public static void main(String args[]){
		CarFieldCheck carFieldCheck = new CarFieldCheck(); // 클래스명 변수이름 = new 클래스명(); 새로운 객체 생성
		System.out.println(carFieldCheck.modelName);
		System.out.println(carFieldCheck.manufacturer);
		System.out.println(carFieldCheck.modelYear);
		
	}

}
