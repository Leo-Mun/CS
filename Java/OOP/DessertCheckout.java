package homework;

import java.util.ArrayList;
import java.util.List;

public class DessertCheckout { // List·Î ¹Ù²ã¼­ ÇØº¾½Ã´Ù
//	private DessertItem[] dessertItems;
	private List<DessertItem> dessertItems;
	private final int maxItems;
	
//	public DessertCheckout (int maxItems) {
//		dessertItems = new DessertItem[maxItems];
//		for (int setNull = 0; setNull < dessertItems.length; ++setNull) {
//			dessertItems[setNull] = null;
//		}
//		
//	}
	
	public DessertCheckout (int maxItems) {
		dessertItems = new ArrayList<DessertItem>();
		this.maxItems = maxItems;
	}
	
//	public boolean enterItem (DessertItem dessertItem) {
//		for (int itemChk = 0; itemChk < dessertItems.length; ++itemChk) {
//			if (dessertItems[itemChk] == null) {
//				dessertItems[itemChk] = dessertItem;
//				
//				return true;
//			}
//		}
//		
//		return false;
//	}
	
	public boolean enterItem (DessertItem dessertItem) {
		if (dessertItems.size() < this.maxItems) {
			dessertItems.add(dessertItem);
			return true;
		} else {
			return false;
		}
	}
	
//	public int getTotalNumberOfItems () {
//		int itemCount = 0;
//		for (int nullChk = 0; nullChk < dessertItems.length; ++nullChk) {
//			if (dessertItems[nullChk] == null) {
//				continue;
//			} else {
//				++itemCount;
//			}
//		}
//		
//		return itemCount;
//	}
	
	public int getTotalNumberOfItems() {
		return dessertItems.size();
	}
	
//	public int getTotalCost() {
//		int totalCost = 0;
//		for (int costChk = 0; costChk < dessertItems.length; ++costChk) {
//			if (dessertItems[costChk] == null) {
//				continue;
//			} else {
//				totalCost += dessertItems[costChk].getCost();
//			}
//		}
//		
//		return totalCost;
//	}
	
	public int getTotalCost() {
		int totalCost = 0;
		for (int costChk = 0; costChk < dessertItems.size(); ++costChk) {
			totalCost += dessertItems.get(costChk).getCost();
		}
		
		return totalCost;
	}
	
//	public void clearItems() {
//		for (int setNull = 0; setNull < dessertItems.length; ++setNull) {
//			dessertItems[setNull] = null;
//		}
//		
//		return;
//	}
	
	public void clearItems() {
		dessertItems.removeAll(dessertItems);
	
		return;
	}
}