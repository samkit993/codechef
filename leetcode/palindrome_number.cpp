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
bool isPalindrome(int x){
	if(x < 0)
		return false;
	int digits=0, temp = x;
	while(temp != 0){
		digits+=1;
		temp/=10;
	}
	temp = x;
	int start = digits, end = 1;
	while(digits > 1){
		int first = temp/ipow(10, digits-1), last = temp % 10;
		if(first != last)
			return false;
		temp -= first*ipow(10, digits-1);
		temp -= last;
		temp /= 10;
		digits -= 2;
	}
	return true;
}
int main(){
	cout << isPalindrome(-2147447412) << endl;
	return 0;
}
