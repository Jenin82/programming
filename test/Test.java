import javax.swing.*;
import java.util.*;

class Test {
	public static void main(String[] args) {
		int n = Integer.parseInt(JOptionPane.showInputDialog("Enter the size of array"));
		int [] arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = Integer.parseInt(JOptionPane.showInputDialog("Enter the element at position "+(i+1)));	
		JOptionPane.showMessageDialog(null, "Array is : "+Arrays.toString(arr));
		Arrays.sort(arr);
		JOptionPane.showMessageDialog(null, "Sorted array : "+Arrays.toString(arr));
		JOptionPane.showMessageDialog(null, "Second smallest element is : "+arr[1]);
	}
}