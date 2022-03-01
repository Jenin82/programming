public class Test {
	public static void main(String[] args) {
		Display d = new Display();
		Sync t1 = new Sync(d,"Hello");
		Sync t2 = new Sync(d,"world");
		t1.start();
		t2.start();
	}
}

class Display {
	public synchronized void display(String msg){
		System.out.print("["+msg);
		try {
			Thread.sleep(100);
		} 
		catch (InterruptedException e) {
			System.out.println(e.getMessage());
		}
		System.out.println("]");
	}
}

class Sync extends Thread {
	private Display d;
	private String msg;
	public Sync(Display d,String msg){
		this.d = d;
		this.msg = msg;
	}
	public void run(){
		d.display(msg);
	}
}
