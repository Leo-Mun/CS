
public class Triangle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 9; j >= i ; j--)
			{
				System.out.print(" ");
			}
			
			for (int j = 1 ; j<=i ; j++)
			{
				System.out.print("*");
			}
			
			System.out.print("\n");
		}
		
		
		
	}

}
