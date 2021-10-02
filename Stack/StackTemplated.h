#include<iostream>
#include <string>
#include <iostream>

using namespace std;
#define ll long long int
#define maxsize 100

template <typename t>
class stack
{
public:
	stack() :top{ -1 } {};
	bool isEmpty();
	t pop();
	void push(t i);
	t Gettop();

private:
	ll top;
	t *a= new t[maxsize] ;
};


template <typename t>
bool stack<t>::isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

template <typename t>
t stack<t>::pop() {
	if (isEmpty()) {
		exit(0);
	}
	else {
		top -= 1;
		return a[top + 1];
	}
}

template <typename t>
void stack<t>::push(t i) {
	top++;
	a[top] = i;
}

template <typename t>
t stack<t>::Gettop() {
	return a[top];
}

bool isDigit(char a) {
	if (a >= '0' && a <= '9') return 1;
	return 0;
}

int solve(int a, int b, char op) {
	switch (op)
	{
	case '*':
		return a * b;
	case '-':
		return b - a;
	case '/':
		return b / a;
	case '+':
		return a + b;
	}
}

bool percidence(char a, char b) {
	switch (a)
	{
	case '*': return 1;
	case '/': return 1;
	case '+':
		switch (b)
		{
		case '*': return 0;
		case '/': return 0;
		default: return 1;
		}
	case '-':
		switch (b)
		{
		case '*': return 0;
		case '/': return 0;
		default: return 1;
		}
	default: return 0;
	}
}



ll solvePre(string& s) {
	stack<int>st;
	ll n = s.length() - 1, i;
	for (i = n; i >= 0; i--) {
		if (isDigit(s[i])) {
			st.push(s[i]-'0');
		}
		else {
			st.push(solve(st.pop(), st.pop(), s[i]));
		}
	}
	return st.pop();
}


ll solvePost(const string& s) {
	stack<int> st;
	ll n = s.length(), i;
	for (i = 0; i < n; i++) {
		if (isDigit(s[i])) st.push(s[i] - '0');
		else {
			ll a = st.pop();
			ll b = st.pop();
			st.push(solve(a, b, s[i]));
		}
	}
	return st.pop();
}

string post(const string& s) {
	stack<char>st;
	string ans = "";
	ll n = s.length(), i;
	for (i = 0; i < n; i++) {
		if (isDigit(s[i])) ans += s[i];
		else {
			if (s[i] == ')') {
				while (st.Gettop() != '(') {
					ans+=st.pop();
				}
				st.pop();
				continue;
			}
			if (s[i] != '(' && s[i] != ')') {
				while (st.isEmpty() == 0 && percidence(st.Gettop(), s[i])) {
					ans += st.pop();
				}
			}
			st.push(s[i]);
		}
		//cout << ans << endl;
	} 
	while (!st.isEmpty()) ans += st.pop();
	return ans;
}

string pre(string s) {
	ll n = s.length(), i;
	for (i = 0; i < n / 2; i++) swap(s[i], s[n - i - 1]);
	for (i = 0; i < n; i++) {
		if (s[i] == '(') s[i] = ')';
		else if (s[i] == ')') s[i] = '(';
	}
	s = post(s);
	n = s.length();
	for (i = 0; i < n / 2; i++) swap(s[i], s[n - 1 - i]);

	return s;
}