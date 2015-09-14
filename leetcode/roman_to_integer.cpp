#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

long long ipow(int base, int power){
	long long ans = 1;
 	while( power != 0){	
		if( power & 1 == 1)
			ans *= base;
		base *= base; 
		power >>= 1;
	}
	return ans;
}
int romanToInt(string s) {
	int values[7] = {1,5,10,50,100,500,1000};
	string symbols[7] = {"I", "V", "X", "L", "C", "D", "M"};
}
int main(){
	return 0;
}
