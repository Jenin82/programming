import java.util.*;
class Test {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the limit of array");
		int n = in.nextInt();
		System.out.println("Enter the array elements");
		int a[] = new int[20];
		for(int i=0;i<n;i++){
			a[i] = in.nextInt();
			System.out.println(a[i]);}
			for(int i=0;i<n;i++)
				for(int j=i;j<=n-i-1;j++)
				{
					if(a[j]>a[j+1]){
						int temp = a[j];
						a[j] = a[j+1];
						a[j+1] = temp;
					}
				}
		System.out.print("Second smallest element is :");
		System.out.println(a[1]);
	}
}