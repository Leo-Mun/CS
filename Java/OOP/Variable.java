import java.util.Scanner;
public class Variable 
{

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
        int month = sc.nextInt();
        int day = sc.nextInt();
        int days = 0;
        
        for (int i = 1 ; i < month ; i++){
            if (i == 1){
                days += 31;
            }
            if (i == 2){
                days += 28;
            }
            if (i == 3){
                days += 31;
            }
            if (i == 5){
                days += 31;
            }
            if (i == 7){
                days += 31;
            }
            if (i == 8){
                days += 31;
            }
            if (i == 10){
                days += 31;
            }
            if (i == 12){
                days += 31;
            }
            else {
                days += 30;
            }
        }
            days += day;
            
            if (days%7 == 0){
                System.out.println("Sun");
            }
             if (days%7 == 1){
                System.out.println("Mon");
            }
             if (days%7 == 2){
                System.out.println("Tue");
            }
             if (days%7 == 3){
                System.out.println("Wed");
            }
             if (days%7 == 4){
                System.out.println("Thu");
            }
             if (days%7 == 5){
                System.out.println("Fri");
            }
            if (days%7 == 6){
                System.out.println("Sat");
            }
        
	                
	}

}
