//Generate subsets of a set represented by a string


#include <bits/stdc++.h>
using namespace std;

void generateSubsets(string word, string curr, int i, int n) {
    if (i==n) {
        cout<<curr<<" ";
        return;
    }
    
    generateSubsets(word, curr, i+1, n);
    generateSubsets(word, curr+word[i], i+1, n);
    
}

int main() {
    
	string word;
	cin>>word;
	
	generateSubsets(word, "", 0, word.length());
}