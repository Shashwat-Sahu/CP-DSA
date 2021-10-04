

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Indexx{

	public static void insert(ArrayList<Integer> arrayList, int data) {
		int ind=arrayList.size();
		arrayList.add(data);
		while(ind!=0) {
			int next=(ind-1)/2;
			if(arrayList.get(ind)<arrayList.get(next)) {
				int x=arrayList.get(next);
				arrayList.set(next, arrayList.get(ind));
				arrayList.set(ind, x);
			}else break;
			ind=next;
		}
	}
	
	public static int remove(ArrayList<Integer> arrayList) {
		int first=arrayList.get(0);
		int n=arrayList.size();
		n-=1;
		arrayList.set(0, arrayList.get(n));
		int last=arrayList.get(0);
		arrayList.remove(n);
		int ind=0;
		while(ind<n) {
			int child1=(ind+1)*2-1,child2=(ind+1)*2;
			if(child2<n) {
				if(arrayList.get(child1)<arrayList.get(child2)&&arrayList.get(child1)<last) {
					int x=arrayList.get(child1);
					arrayList.set(child1, last);
					arrayList.set(ind, x);
					ind=child1;
				}else if(arrayList.get(child2)<last){
					int x=arrayList.get(child2);
					arrayList.set(child2, last);
					arrayList.set(ind, x);
					ind=child2;
				}else break;
			}else if(child1<n){
				if(arrayList.get(child1)<last) {
					int x=arrayList.get(child1);
					arrayList.set(child1, last);
					arrayList.set(ind, x);
					ind=child1;
				}
				break;
			}else break;
		}
		return first;
	}
	
	public static void main(String[] args) {
		int[] arr= {32,6,78,34,54,76,6,34,56,7};
		ArrayList<Integer> arrayList=new ArrayList<>();
		for(int i=0;i<10;i++) {
			insert(arrayList,arr[i]);
		}
		
		System.out.println(arrayList.toString());
		for(int i=9;i>=0;i--) {
//			System.out.println(arrayList.toString());
			arr[i]=remove(arrayList);
		}
		System.out.println(Arrays.toString(arr));

	}

}

