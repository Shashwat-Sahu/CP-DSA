#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;

        if(s.size()<=1) return false;

        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }

            else if(s[i]=='}'){
                if(st.empty() || st.top()!='{'){
                    return false;
                }
                else st.pop();
            }

            else if(s[i]==')'){
                if(st.empty() || st.top()!='(' ){
                    return false;
                }
                else st.pop();
            }

            else if(s[i]==']'){
                if(st.empty() || st.top()!='[' ){
                    return false;
                }
                else st.pop();
            }

            else return false;
        }
        
        if(st.empty())return true;
        else return false;
}


int main(){ 
    string s;
    cin>>s;

    if(isValid(s)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}

//Time Complexity- O(n)
