
public class ArrayInitiallizing {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] Arr = new int[10];
		int[] Arr2 = new int[10];
		
		for (int i = 0 ; i < Arr.length ; i++)
		{
			Arr[i] = i ;
			System.out.println("Array[" + i + "] : " + Arr[i]);
		}
		
		
		
		for (int i = 0 ; i < Arr2.length ; i++)
		{
			int N = (int)(Math.random() * 10);
			Arr2[i] = Arr[N];
			System.out.println("Array2[" + i + "] : " + Arr2[i]);
		}
		
		
		
		
	}

}
