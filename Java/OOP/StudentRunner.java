package homework;


public class StudentRunner {
    public static void main(String[] args) {
        Student kim = new Student("2016000");
        Student lee = new Student("2016001", 3.0);
        CollegeStudent park = new CollegeStudent("2016002", 3.5, "Computer Science");

        System.out.println(kim);
        System.out.println(lee);
        System.out.println(park);
    }
}
