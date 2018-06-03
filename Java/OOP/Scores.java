
public class Scores {

	public static void main(String[] args) {
		int[] Scores = {90, 85, 100, 70, 95};
		
		int Sum = 0;
		
		
		for (int s  : Scores)
		{
			Sum += s;
		}
		
		System.out.println("Sum : " + Sum);
		System.out.println("Avg : " + Sum / Scores.length);
	}

}
