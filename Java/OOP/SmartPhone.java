package kr.ac.kookmin.cs.oop.inheritance.interfaceclass.impl;

import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.MusicPlayable;
import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.PhoneCallable;
import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.PhotoTakable;

public class SmartPhone extends CellPhone implements MusicPlayable, PhotoTakable {
	
	@Override
	public void takeShot() {
		System.out.println("Taking a photo from a Smartphone");
	}
	
	@Override
	public void play() {
		System.out.println("Play music from SmartPhone");
	}
	
	@Override
	public void stop() {
		System.out.println("Stop music");
	}

}