#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool isValid(string s) {
	stack<char> st;
	st.push(s[0]);
	for(int i=1;i<s.size();++i){
		if(!st.empty() && ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')))
			st.pop();
		else
			st.push(s[i]);
	}
	return st.empty();
}
int main(){
	string s = "{()}[]";
	cout << isValid(s) << endl;
	return 0;
}
