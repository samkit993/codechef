#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
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
int main(){
	string x = "abc";
	int a = 123;
	cout << x + itos(a) << endl;
	return 0;
}
