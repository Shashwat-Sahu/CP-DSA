#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int,vector<int>> pqx;
priority_queue<int,vector<int>,greater<int>> pqn;

void insert(int val){
    if(pqx.size()==pqn.size()){
        if(pqx.size()==0){
            pqx.push(val);
            return;
        }
        if(val < pqx.top()){
            pqx.push(val);
        }
        else{
            pqn.push(val);
        }
    }
    else{
        if(pqx.size() > pqn.size()){
            if(val >= pqx.top()){
                pqn.push(val);
                return;
            }
            else{
                pqn.push(pqx.top());
                pqx.pop();
                pqx.push(val);
            }
        }
        else{
            if(val <= pqn.top()){
                pqx.push(val);
                return;
            }
            else{
                pqx.push(pqn.top());
                pqn.pop();
                pqn.push(val);
            }
        }
    }
}


int main(){
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int inp;
		cin >> inp;
		insert(inp);
		if (pqx.size() == pqn.size())
		{
			cout<<"median : "<< (pqx.top() + pqn.top()) / 2.0<<endl;
		}
        else if (pqx.size() < pqn.size()){
			cout<<"median : "<< pqn.top()<<endl;
        }
		else
		{
			cout<<"median : "<< pqx.top()<<endl;
		}
    }
    
    return 0;
}