
public class Reverse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num = 345713046;
		int num2 = 0;
		
		while (num != 0)
		{
			num2 *= 10;
			num2 += num%10;
			num /= 10;
		}
		
		System.out.println(num2);
		
		
	}

}
