public class Capital {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		char symbol = (char)(Math.random() * 128);
		
		char A = 65, Z = 90, a = 97, z = 122;
		
		System.out.println(symbol);
		
		if (A <= symbol && symbol <= Z)
		{
			System.out.println("It is a Capital letter.");
		}
		else if (a <= symbol && symbol <= z)
		{
			System.out.println("It is a Small letter.");
		}
		else 
		{
			System.out.println("It is a symbolic letter.");
		}
		
		
		

		
		
		
		
	}

}
