package Exercise;

public class FinalStatic {
	public static final String KOOKMIN_UNIV_OFFICIAL_NAME = "Kookmin University";   
	public static final String KMU_ADDRESS = "Jeonnung Ro 77, Seongbuk Gu, Seoul. South Korea";
	private final String birthNation = "Korea";
	private final String birthYear; // final 에서 초기화 안하면 Constructor 에서 초기화 해야함
	private String name;
	
	public FinalStatic(String birthYear, String name){
		this.birthYear = birthYear;
		this.name = name;
	}
	
	public void setBirthYear(String birthYear){
		// this.birthYear = birthYear;
	}
	
}
