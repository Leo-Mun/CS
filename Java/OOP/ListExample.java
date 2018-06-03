package kr.ac.kookmin.cs.oop.collections;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class ListExample {
	private List<String> slackIds = new ArrayList<String>();

	public ListExample() {
		slackIds = new LinkedList<String>();
		slackIds.add("leeky");
		slackIds.add("1g");
		slackIds.add("20132368");
	}
	
	public void iterateIds() {
		for (String id : slackIds) {
			System.out.println(id);
		}
		
		System.out.println(slackIds.get(1));
		slackIds.remove(1);
		System.out.println(slackIds.size());
		System.out.println(slackIds.get(1));
		slackIds.add("20163080");
		System.out.println(slackIds.size());
		
	}
	
	public static void main(String[] args) {
		ListExample listExample = new ListExample();
		listExample.iterateIds();
		
	}
}