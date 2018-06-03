public class D_9_22 {

	public static void main(String[] args) {
		/*
		int addAssign = 10;
		addAssign += 20;
		System.out.println("value is " + addAssign);
		addAssign = addAssign + 20;
		System.out.println("value is " + addAssign);
		
		int overflow1 = 2000000000;
		int overflow2 = 2000000000;
		int overflowResult = overflow1 + overflow2;
		System.out.println("output is : " + overflowResult);
		
		long overflow3 = 2000000000L;
		long noOverflow = overflow1 + overflow3;
		System.out.println("no overflow output is : " + noOverflow);
		System.out.println("int " + (overflow1/ 1000000) + " double " + (overflow1 / 100000.0));
		*/
		
		int errorX = 5;
		double errorY = 0.0 ;
		
		//double errorResult = errorX / errorY ;
		double errorResult = errorX % errorY;
		
		System.out.println(Double.isInfinite(errorResult));
		System.out.println(Double.isNaN(errorResult));
		
		String s1 = "Hello";
		String s2 = " Java";
		String s3 = "!!";
		String out = s1 + s2 + s3;
		System.out.println(out);
		
		
		
		
		
		}

}