package kr.ac.kookmin.cs.oop.inheritance.abstractclass;

public abstract class Mammal extends Animal {
	
	@Override
	protected void breathe() {
		System.out.println("breathe using lung");
	}

}
