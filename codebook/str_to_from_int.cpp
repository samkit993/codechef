#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#define FOR(start, end) "for(int i=start;i<end;++i)"
#define REVFOR(end, start) "for(int i=end-1;i>=start;--i)"

#define DEBUG 0	
using namespace std;

string itos(unsigned long long a){
	string str;	
	while(a > 0){
		str += (char( '0' + a % 10));
		a /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

unsigned long long stoi(string str){
	unsigned long long ans = 0; 
	int n = str.size();
	for(int i=n-1;i>=0;--i){
		ans += ((int)(str[i] - '0'))*ipow(10, n-1-i);
	}
	return ans;
}

int main(){
	cout << stoi("1000212222");
}
