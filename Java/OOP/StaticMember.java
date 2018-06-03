package Exercise;

public class StaticMember {

	String color; // 객체가 생설될 때마다 color 값은 달라질 수 있음
	static double pi = 3.14159265;
	
	static int plus(int x, int y){ // 인자들이 객체 내부 인스턴스와 관련 X >> static
		return x + y;
	}
	
	static int minus(int x, int y){ // ...
		return x - y;
	}
	
	double test () {
		return pi;
	}
	
	void setColor(String color){ // static 쓰면 this 못 씀(객체와 종속됐기 때문)
		this.color = color;
	}
	
	String getColor(){ // ...
		return color;
	}
	
	public static void main(String[] args){ // 자바는 무조건 main 함수를 찾아서 실행시킴(main이 여러 개 일 수도 있음)
		StaticMember staticExercise = new StaticMember(); // 객체 생성
//		 System.out.println(this.color); //(static 때문에 this. 를 못 씀 - 객체와 연관X)
		staticExercise.setColor("Blue");
		StaticMember staticExercise2 = new StaticMember();
		System.out.println(staticExercise.color + staticExercise2.color);
		int radius = 5;
		double sizeOfCircle = StaticMember.pi * radius * radius; // recommended (Static Member 를 부르려면 
		sizeOfCircle = staticExercise.pi * radius * radius; // not recommended   객체를 쓰는 것보단 클래스 이름을 써주는 것이 좋음)
	}
	
	
}