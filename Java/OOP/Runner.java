package kr.ac.kookmin.cs.oop.inheritance.interfaceclass.impl;

import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.MusicPlayable;
import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.PhoneCallable;
import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.PhotoTakable;

public class Runner {
	public static void main(String[] args) {
		PhoneCallable phone = new TelePhone();
		phone.call(29104220);
		
		phone = new CellPhone();
		phone.call(29104220);
		
		MusicPlayable mp3Player = new Mp3Player();
		mp3Player.play();
		mp3Player.stop();
		
		mp3Player = new SmartPhone();
		mp3Player.play();
		mp3Player.stop();
		
		PhotoTakable camera = new DigitalCamera();
		camera.takeShot();
		
		camera = new SmartPhone();
		camera.takeShot();
		
		SmartPhone smartPhone = new SmartPhone();
		camera = smartPhone;
		
		smartPhone.takeShot();
		camera.takeShot();
	}
}