#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<unordered_map>

#include<set>
using namespace std;

#define ll long long int

int arr[1001];
int len[] = { 1,2,3,4,5,6,7,8,9,10 };
int price[] = { 1,5,8,9,10,17,17,20,24,30 };

int findAns(int l, int n) {
	if (l < 0)return -20000;
	if (l == 0)return 0;
	if (arr[l] != -1)return arr[l];
	int ans = 0;
	for (int i = 0; i < min(l, n); i++) {
		ans = max(ans, findAns(l - i - 1, n)+price[i]);
	}
	arr[l] = ans;
	return ans;
}

int find(int l,int n) {
	int* ary = new int[l + 1];
	for (int i = 0; i <= l; i++)ary[i] = 0;
	for (int i = 0; i <= l; i++) {
		int ans = 0;
		for (int j = 0; j < min(n,i); j++) {
			ans = max(ans, price[j] + ary[i - j - 1]);
		}
		ary[i] = ans;
		//cout << ary[i] << " ";
	}
	return ary[l];
}

int main() {
	for (int i = 0; i < 1001; i++)arr[i] = -1;
	cout << find(99999, 10);

	


	return 0;
}