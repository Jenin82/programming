import javax.swing.*;
import java.util.*;

class Test {
	public static void main(String[] args) {
		String s = JOptionPane.showInputDialog("Enter the string");
		char c[] = s.toCharArray();
		int [] freq = new int[s.length()];
		for(int i=0;i<s.length();i++){
			freq[i]=1;
			for(int j=i+1;j<s.length();j++)
			if(c[i] == c[j]){
					freq[i]++;
					c[j] = '0';
			}
		}
		for(int i=0;i<s.length();i++)
			if(c[i] != '0') 
				JOptionPane.showMessageDialog(null, "Frequency of "+c[i]+" = "+freq[i]);
	}
}