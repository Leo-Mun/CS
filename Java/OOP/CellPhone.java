package kr.ac.kookmin.cs.oop.inheritance;

public class CellPhone {
	protected String model;
	protected String color;
	public void powerOn() {
		System.out.println("Power ON");
	}	
	
	public void powerOff() {
		System.out.println("Power OFF");
	}
	
	protected void sendMessage() {
		System.out.println("Sending a message");
	}
}
