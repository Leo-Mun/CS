package homework;

public abstract class DessertItem {
	private String name;
	
	public DessertItem (String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}
	
	public abstract int getCost();
}