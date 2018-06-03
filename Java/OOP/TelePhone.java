package kr.ac.kookmin.cs.oop.inheritance.interfaceclass.impl;

import kr.ac.kookmin.cs.oop.inheritance.interfaceclass.PhoneCallable;

public class TelePhone extends PhoneCallable {
	@Override
	public void call(int number) {
		System.out.println("Wired phone call : " + number);
	}
	@Override
	public void hangup() {
		System.out.println("hangup wired phone call");
	}
}