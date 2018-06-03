package kr.ac.kookmin.cs.oop.inheritance;

public class TypeCasting {
	public static void main(String[] args) {
		SmartWatch smartWatch = new SmartWatch("Apple", "white", "AppStore");
		smartWatch.runBrowser();
		
		CellPhone cellPhone = smartWatch;
//		 cellPhone.runBrowser();
		cellPhone = (SmartPhone) smartWatch;
		SmartPhone smartPhone = (SmartPhone) cellPhone;
		smartPhone.runBrowser();
		System.out.println(cellPhone instanceof SmartWatch);
		System.out.println(cellPhone instanceof SmartPhone);
	}
}
