#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int ipow(int b,int p){
	int ans = 1;
	while(p > 0){
		if(p & 1 == 1)
			ans *= b;
		b *= b;
		p >>= 1;
	}
	return ans;
}
int myAtoi(string str){
	long long int ans = 0; 
	bool minus = false;
	if(str.substr(0,2) == "-+" || str.substr(0,2) == "+-")
		return 0;
	if(str[0] == '-'){
		minus = true;
		str = str.substr(1,str.size());
	}
	if(str[0] == '+'){
		str = str.substr(1,str.size());
	}
	while(str[0] == ' '){
		str = str.substr(1,str.size());
	}
	int n = str.size();
	for(int i=n-1;i>=0;--i){
		ans += ((int)(str[i] - '0'))*ipow(10, n-1-i);
	}
	ans = (minus) ? -ans : ans;
	ans = (ans > INT_MAX) ? 0 : ans;
	ans = (ans < INT_MIN) ? 0 : ans;
	return ans;
}

int main(){
	cout << myAtoi("         22");
}
