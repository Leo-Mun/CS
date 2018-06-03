import java.util.ArrayList;
import java.util.List;

public class ListChk {
	List<Integer> iNumber = new ArrayList<Integer>();
	List<Double> dNumber = new ArrayList<Double>();
	List<Float> fNumber = new ArrayList<Float>();
	
	void add () {
		iNumber.add(1);
		dNumber.add(1.0);
		fNumber.add((float) 1.0);
	}
	
	public static void main(String[] args) {
		ListChk listChk = new ListChk();
		listChk.add();
		System.out.println(listChk.iNumber.get(0));
		System.out.println(listChk.dNumber.get(0));
		System.out.println(listChk.fNumber.get(0));
		
		
	}
}
