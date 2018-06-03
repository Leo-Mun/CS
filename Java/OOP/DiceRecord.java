
public class DiceRecord {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		int num, one=0, two=0, three=0, four=0, five=0, six=0;
		
		
		for (int i = 1; i <= 10000; i++)
		{
			num = (int) (Math.random() * 6) + 1;
			
			if (num == 1)
			{
				one++;
			}
			if (num == 2)
			{
				two++;
			}
			if (num == 3)
			{
				three++;
			}
			if (num == 4)
			{
				four++;
			}	
			if (num == 5)
			{
				five++;
			}
			if (num == 6)
			{
				six++;
			}
		
			
			
			
		}
		
		System.out.println("one : " + one);
		System.out.println("two : " + two);
		System.out.println("three : " + three);
		System.out.println("four : " + four);
		System.out.println("five : " + five);
		System.out.println("six : " + six);
		
		
	}

}
