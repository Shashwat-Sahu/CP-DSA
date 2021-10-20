#include <bits/stdc++.h>
using namespace std;

//function to print next greater element for all elements of arr[] of size n
void findnextgreater(int arr[], int n)
{
	stack<int> s;
	int res[n];
	for (int i = n - 1; i >= 0; i--) {
		if (!s.empty()) {
			while (!s.empty() && s.top() <= arr[i]) {
				s.pop();
			}
		}
		res[i] = s.empty() ? -1 : s.top();
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
	int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

	findnextgreater(arr, n);
	return 0;
}
