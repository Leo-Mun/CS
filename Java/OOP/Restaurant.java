package kr.ac.kookmin.cs.oop.inheritance.abstractclass;

public abstract class Restaurant {
	private String name;
	private String dishes;
	
	protected abstract void cook(String menu);
		// cook whatever a child class wants to
	
}
