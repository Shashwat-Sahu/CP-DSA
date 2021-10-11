#include<bits/stdc++.h>
using namespace std;
bool checkRedundantBrackets(string s) {
	
    bool ans =false;
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='(')
                ans=true;
            while(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/')
                st.pop();
            st.pop();
        }
    }
    return ans;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}