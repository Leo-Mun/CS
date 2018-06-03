package Exercise;

public class AccessModifier extends Object {
	private String name;
	private String id;
	int years; // default 같은 패키지 안에서 접근 가능
	public String phoneNumber;
	
	public void setName(String name){
		this.name = name;
	}
	
	protected String getID(){
		return id;
	}
	
	public void doHomework(){
		reviewClass();
	}
	
	private void reviewClass(){ // private 외부에서 호출 X
			
		
	}
}
