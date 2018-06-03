package kr.ac.kookmin.cs.oop.inheritance.abstractclass;

public abstract class Animal {
	private String species;
	
	protected abstract void breathe() ; // abstract 메소드는 함수 바디를 가져선 안됨
	
	public abstract String sound();
	
}
