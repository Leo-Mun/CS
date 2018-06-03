public class Input {

	public static void main(String[] args) {
		
		int[] input = new int[100];
		int[] output = new int[10];
		
		for (int i = 0 ; i < input.length ; i++)
		{
			int N = (int)(Math.random() * 10) + 1 ;
			input[i] = N ;
		}
		
		for (int s : input)
		{
			switch (s)
			{
			case 1 : 
				output[0]++;
				break;
			case 2 : 
				output[1]++;
				break;
			case 3 : 
				output[2]++;
				break;
			case 4 : 
				output[3]++;
				break;
			case 5 : 
				output[4]++;
				break;
			case 6 : 
				output[5]++;
				break;
			case 7 : 
				output[6]++;
				break;
			case 8 : 
				output[7]++;
				break;
			case 9 : 
				output[8]++;
				break;
			case 10 : 
				output[9]++;
				break;
			
			}
				
		}
		
		for (int i = 0 ; i < output.length ; i++)
		{
			System.out.println("output[" + i + "] = : " + output[i]);
		}
		
		
		
		
		
		

	}

}
