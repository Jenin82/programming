import java.util.*;
public class Test {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the numbers (separated by spaces)");
		String str = sc.nextLine();
		StringTokenizer st = new StringTokenizer(str," "); 
		int sum = 0;
		while(st.hasMoreTokens()){
			sum += Integer.parseInt(st.nextToken());
		}
		System.out.println("Sum = "+sum);
	}
}
