package Assignment4;

public class Member {
	
	private String name;
	private String id;
	private String password;
	private int age;
	
	
	public Member(String name, int age){
		this.name = name;
		this.age = age;
	}
	
	private boolean login(String id, String password){
		if (this.name == id && this.password == password){
			return true;
		}	
		else {
			return false;
		}
	}
	
	void logOut() {
		System.out.println("You are logged out");
	}
		
		
	
}
