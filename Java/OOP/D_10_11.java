public class D_10_11 {

	public static void main(String[] args) {
	
	
		String class1 = "Java Programming";
		String class2 = "Java Programming";
		String class3 = new String("Java Programming"); // new 는 문자열이 같더라도 강제로 힙 영역의 새로운 공간에 문자열을 저장시킴
	
		System.out.println(class1 + " " + class2 + " " + class3);
	
		System.out.println(class1 == class2); // 문자열이 같으면 힙 영역 내의 같은 공간에 문자열을 저장함.
		System.out.println(class1 == class3);
		System.out.println(class1.equals(class3));
	
		// type[] name = {};
	
		// int[] intArray = null;
		// intArray = new int[n]; n개의 영역을 int형으로 힙 영역에 만들어라 그리고 스택 영역에서 그 주소를 참조해라.
	
	/*
		int[] scores = {83, 90, 87};
		System.out.println("Array length is " + scores.length);
	
		System.out.println("scores[0] : " + scores[0]);
		System.out.println("scores[1] : " + scores[1]);
		System.out.println("scores[2] : " + scores[2]);
		
		
		int sum = 0 ;
		for (int i = 0 ; i < 3 ; i++)
		{
			sum += scores[i];
		}
		System.out.println("Sum : " + sum);
		double avg = (double)sum/3; // 1.0 곱해줘도 실수형 type 됨.
		System.out.println("Average : " + avg);
		
	*/
	
		// 배열도 reference type임	
		
		
	/*
		String[] courses = null;   
		courses = new String[] { "Java", "Software", "C++" };  // 배열의 새로운 주소를 참조할 수 있는 영역이 힙 영역에 생성되고 그 주소를 스택 영역에 참조.
	
	
		int[] arr1 = new int[3];  // 공간만 잡아놓으면 공간에 0으로 자동 초기화해줌.
		for (int i = 0; i < 3; i++) 
    	{      
    	 	System.out.println("arr1[" + i + "] : " + arr1[i]);     
    	}    
     
     	arr1[0] = 10;   
     	arr1[1] = 20; 
     	arr1[2] = 30;   
     
    	for (int i = 0; i < 3; i++) 
    	{    
    	 	System.out.println("arr1[" + i + "] : " + arr1[i]); 
    	}
	*/
		
		/*
		
		String[] arr3 = new String[3]; // String은 초기화를 안해주면 null값 대입, 스택 영역은 역시 주소가 참조됨
		for (int i = 0 ; i < 3 ; i++)
		{
			System.out.println("arr3["+ i + "] : " + arr3[i]);
		}
		arr3[0] = "Jan.";
		arr3[1] = "Frb.";
		arr3[2]	= "March";
		for (int i = 0 ; i < 3 ; i++)
		{
			System.out.println("arr3[" + i + "] : " + arr3[i]);
		}
		
		*/
		
    
    
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}

}