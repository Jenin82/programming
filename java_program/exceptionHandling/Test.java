import java.util.Scanner;
public class Test {
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(System.in);
			System.out.println("Enter the two numbers to perform division");
			int a = in.nextInt();
			int b = in.nextInt();
			divide(a, b);
		} 
		catch (Exception e) {
			System.out.println(e.getMessage());	
		}
		finally{
			System.out.println("End of program");
		}
	}

	public static void divide(int c,int d) throws ArithmeticException{
		if(d == 0)
			throw new ArithmeticException("Divide by zero not possible");
		else {
			System.out.println("Result = "+c/d);
		}
	}
}
