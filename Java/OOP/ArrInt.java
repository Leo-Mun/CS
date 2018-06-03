public class ArrInt {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[][] Arr = new int[4][5];
		int[][] Arr2 = new int[4][5];
		int num = 1;
		int num2 = 1;
		
		for (int i = 0 ; i < Arr.length ; i++)
		{
			for (int j = 0 ; j < Arr[i].length ; j++)
			{
				Arr[i][j] = num++ ;
				System.out.println("Arr["+i+"]["+j+"]"+" : " + Arr[i][j]);
			}
		}
		
		
		for (int i = 0 ; i < Arr2[0].length ; i++)
		{
			for (int j = 0 ; j < Arr2.length ; j++)
			{
				Arr2[j][i] = num2++;
				System.out.println("Arr2["+j+"]["+i+"] : "+ Arr2[j][i]);
			}
		}
		
		
		
	}

}
