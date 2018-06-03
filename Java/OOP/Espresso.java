package homework;

public class Espresso extends DessertItem {
	private final int numberOfShots;
	private static final int SINGLE_SHOT_PRICE = 1000;
	
	public Espresso(String name, int numberOfShots) {
		super(name);
		this.numberOfShots = numberOfShots;
	}
	
	@Override
	public int getCost() {
		return numberOfShots * Espresso.SINGLE_SHOT_PRICE;
	}
	
}
