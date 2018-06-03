package Exercise;

public class GetterSetter {
	private int speed = 0; // 필드는 무조건 private로 하는 습관
	private boolean stopped = false;
	
	public boolean isStopped(){ // boolean 은 is 아니면 get
		return stopped;
	}
	
	public int getSpeed() { // 값을 받아올 땐 Getter, 값 설정은 Setter
		return speed;
	}
	
	public void setSpeed(int speed) { // getter, setter 를 잘 설정해주는것이 중요함
		if (speed < 0) {
			this.speed = 0;
			return;
		} else {
			this.speed = speed;
		}
	}
	
	
		
}
