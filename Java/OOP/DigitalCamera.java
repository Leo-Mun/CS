package kr.ac.kookmin.cs.oop.inheritance.interfaceclass.impl;

import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.PhotoTakable;

public class DigitalCamera implements PhotoTakable {
	
	@Override
	public void takeShot() {
		System.out.println("Taking a picture using Digital Camera");
	}
}
