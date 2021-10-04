#include<bits/stdc++.h>
using namespace std;
#define dd double
#define ll long long int
#define light ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define t_pair pair<ll,pair<ll,ll>>
ll INF=1e9+5;
ll mod=998244353;

class Stack{
	private:
		queue<int> q1;
		queue<int> q2;
		
	public:
		void push(int x);
		int pop();
};

void Stack::push(int x){
	if(!q2.empty()){
		q2.push(x);
	}else{
		q1.push(x);
	}
}

int Stack::pop(){
	if(q1.empty() && q2.empty()){
		return -1;
	}
	
	if(!q1.empty()){
		int x;
		while(!q1.empty()){
			x = q1.front();
			q1.pop();
			
			if(x == q1.back()){
				return x;
			}else{
				q2.push(x);
			}
		}
	}else{
		int x;
		while(!q2.empty()){
			x = q2.front();
			q2.pop();
			
			if(x == q2.back()){
				return x;
			}else{
				q1.push(x);
			}
		}
	}
}

int main()
{
	//	#ifndef ONLINE_JUDGE
	//	freopen("input1.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	//	#endif

	//	light;
	Stack s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	
	s.push(7);
	cout<<"\nPoped out element is "<<s.pop();
	
	s.push(8);
	s.push(9);
	s.push(10);
	
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	cout<<"\nPoped out element is "<<s.pop();
	
	return 0;
}

