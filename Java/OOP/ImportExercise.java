package Exercise; // 같은 패키지의 클래스를 참조하려면 import 안써도 됨

import kr.ac.kookmin.ac.kr.cs.calculus.Class; // 다른 패키지의 클래스를 참조하려면 import 를 사용해야함
// import kr.ac.kookmin.cs.oop.Class; // Class 이름이 같아서 안됨
import kr.ac.kookmin.ac.kr.cs.calculus.FormulaSheet; // * 는 패키지 안에 있는 모든 것을 참조(웬만하면 쓰지마셈)


public class ImportExercise {
	Class myClass = new Class();
	FormulaSheet myFormulaSheet = new FormulaSheet();

}
