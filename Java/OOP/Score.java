public class Score {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		System.out.print("Your Score : ");
		int score = 89;
		String grade = "A+";
		
		if (95 < score)
		{
			grade = "A+";
		}
		else if (90 <= score)
		{
			grade = "A";
		}
		else
		{
			grade = "B+";
		}
		
		switch (grade)
		{
		case "A+" :
			System.out.println(grade);
			break;
		case "A" :
			System.out.println(grade);
			break;
		case "B+" :
			System.out.println(grade);
			break;
			
			
		}
		
		
		
		
		
		
	}

}
