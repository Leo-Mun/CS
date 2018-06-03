public class splitOutput {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String[] splitOutput = new String[3];
		String input = "Object Oriented Programming,Open Source Software Programming,BigData Analysis";
		
		splitOutput = input.split(","); // split 후 배열에 넣으면 배열 칸에 맞게 알아서 들어감
		
		for (int i = 0 ; i < splitOutput.length ; i++)
		{
			System.out.println("splitOutput[" + i + "] : " + splitOutput[i]);
		}
		
		System.out.println("\n");
		
		for (int i = 0 ; i < splitOutput.length ; i++)
		{
			System.out.println("splitOutput[" + i + "] : " + splitOutput[i].equals("Object Oriented Programming"));
			System.out.println("length : " + splitOutput[i].length());
			System.out.println("Location of the letter Programming : " + splitOutput[i].indexOf("Programming"));
		}
		
		
		
		
	}

}
