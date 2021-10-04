#include <bits/stdc++.h>
using namespace std;

int main() {
    
	string word;
	cin>>word;
	
	int n = word.length();
	
	int subSetCount = pow(2, n);
 
    for(int i = 0; i < subSetCount; i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) //checking each character of string and if its set in generated counter
                cout << word[j];
        }
        cout << endl;
    }

}