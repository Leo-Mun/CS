package homework;

public class CollegeStudent extends Student {
	private String major;
	
	public CollegeStudent (String studentId, double grade, String major) {
		super(studentId, grade);
		this.major = major;
	}
	
	@Override
	public String toString() {
		return "Id : " + this.studentId + " " + "Grade : " + this.grade + " " + "Major : " + this.major;
	}
}

