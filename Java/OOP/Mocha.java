package homework;

public class Mocha extends Espresso {
	private final int weightOfChocolate;
	private final int weightOfMilk;
	private static final int MILK_PRICE_PER_GRAM = 50;
	private static final int CHOCOLATE_PRICE_PER_GRAM = 100;
	
	public Mocha (String name, int numberOfShot, int weightOfChocolate, int weightOfMilk) {
		super(name, numberOfShot);
		this.weightOfChocolate = weightOfChocolate;
		this.weightOfMilk = weightOfMilk;
	}
	
	@Override
	public int getCost() {
		int espressoCost = super.getCost();
		int mochaCost = weightOfChocolate * Mocha.CHOCOLATE_PRICE_PER_GRAM + weightOfMilk * Mocha.MILK_PRICE_PER_GRAM;
		return espressoCost + mochaCost;
	}
}

