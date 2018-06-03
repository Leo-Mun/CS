package homework;

public class Cookie extends DessertItem {
	
	private final int numberOfItems;
	private final int pricePerItem;
	
	public Cookie(String name, int numberOfItems, int pricePerItem) {
		super(name);
		this.numberOfItems = numberOfItems;
		this.pricePerItem = pricePerItem;
	}
	
	@Override
	public int getCost() {
		return numberOfItems * pricePerItem;
	}
	
}