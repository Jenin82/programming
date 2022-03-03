import java.util.*;
public class Test {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the string");
		String s = in.nextLine();
		int freq[] = new int[s.length()];
		char a[] = s.toCharArray();
		for(int i=0;i<s.length();i++){
			freq[i]=1;
			for(int j=i+1;j<s.length();j++){
				if(a[i]==a[j]){
					freq[i]++;
					a[j]='0';
				}
			}
		}
		System.out.println("Freqencies are :");
		for(int i=0;i<s.length();i++)
			if(a[i] != '0')
				System.out.println(a[i]+"-"+freq[i]);
	}
}
