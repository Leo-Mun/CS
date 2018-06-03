package kr.ac.kookmin.cs.oop.inheritance;

public class Student extends People {
	private int studentNo;
	
	public Student(String name, String ssn, int studentNo) { // 부모클래스의 Constructor가 인자를 가질 경우 super을 사용해야함
		super(name, ssn); // 부모 클래스의 Constructor 을 호출
		this.studentNo = studentNo;
		
	}

}