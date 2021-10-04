

import java.util.Arrays;
import java.util.Scanner;

public class Matmul{

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int n= input.nextInt();
		
		int[][] a=new int[n][n];
		int[][] b=new int[n][n];
		int[][] c=new int[n][n];
		
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=input.nextInt();
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i][j]=input.nextInt();
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				int cur=0;
				for(int k=0;k<n;k++) cur+=a[i][k]*b[k][j];
				c[i][j]=cur;
			}
		}
		for(var i:c) {
			System.out.println(Arrays.toString(i));
		}
		
		input.close();
	}

}

