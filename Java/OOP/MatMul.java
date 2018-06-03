public class MatMul {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[][] matMulLeft = new int[5][10]; //matrix multiplication
		int[][] matMulRight = new int[10][5];
		int[][] matMulResult = new int[5][5];
		
		for (int i = 0 ; i < matMulLeft.length ; i++)
		{
			for (int j = 0 ; j < matMulLeft[i].length ; j++)
			{
				matMulLeft[i][j] = (int)((Math.random() * 10) + 1);
			}
		}
		
		for (int i = 0 ; i < matMulRight.length  ; i++)
		{
			for (int j = 0 ; j < matMulRight[i].length ; j++)
			{
				matMulRight[i][j] = (int)((Math.random() * 10) + 1);
			}
		}
		
		
		for (int i = 0 ; i < matMulLeft.length ; i++)
		{
			
			for (int j = 0 ; j < matMulRight[j].length ; j++)
			{
				for (int k = 0 ; k < matMulLeft[i].length ; k++)
				{
					matMulResult[i][j] += matMulLeft[i][k] * matMulRight[k][j];
				}
			}
		}
		
		
		
	}

}
