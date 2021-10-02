#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    int i,k=0;
    for( i=0;i<s1.size();i++)
	 {
	 for(int j=0;j<s2.size();j++){
		if(s1[i]==s2[j]){
		k=1;
		break;}
	}if(k==0)
	 break;
	 k=0;
		}	
	if(i==s1.size())
	cout<<"Yes. Two strings are anagram of each other";
	else
	cout<<"No. Two strings are not anagram of each other";
	return 0;
}
