public class BankInterest {

	public static void main(String[] args) {
		double Total = 1000000;
		
		double F_Year = Total + Total*0.03;
		double S_Year = F_Year + F_Year*0.03;
		double T_Year = S_Year + S_Year*0.03;
		double Fo_Year = T_Year + T_Year*0.03;
		double Fi_Year = Fo_Year + Fo_Year*0.03;
		
		System.out.println(Total);
		System.out.println(F_Year);
		System.out.println(S_Year);
		System.out.println(T_Year);
		System.out.println(Fo_Year);
		System.out.println(Fi_Year);
	}

}
