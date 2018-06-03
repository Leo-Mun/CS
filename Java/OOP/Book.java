package homeword;

public class Book {
	
	private String title;
	private boolean inPlace = true;
	private boolean canRent = false;
	
	public Book(String title) {
		
		this.title = title;
	}
	
	public boolean isInPlace() {
		
		return this.inPlace;
	}
	
	public String getTitle() {
		return title;
	}
	
	public void rent() {
		if (this.inPlace == true) {
			
			this.inPlace = false;
			canRent = false;
			System.out.println("You rented " + title);
		
		}
		
		else 
			System.out.println(title + " is already rented");
		
		return;
	}
	
	public boolean getRent() {
		return canRent;
	}
	
	public void setRent() {
		if (inPlace == true) { 
			inPlace = false;
			canRent = true;
			
		}

		else
			this.canRent = false;
		
		return;
		
	}
	
	public void handIn() {
		if (this.inPlace == false) {
			
			this.inPlace = true;
			System.out.println("Thank you for returning " + title);
		
		}
		
			else	
				System.out.println(title + " is not rented yet (you cannot return it)");
			
		return;
		
	}
	
	public void setHandIn() {
		if (inPlace == false) 
			inPlace = true;
		
		return;
	}
	
	
}