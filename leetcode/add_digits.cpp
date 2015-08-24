#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int addDigits(int num) {
	if (num == 0)
		return 0;
	if(num % 9 == 0)
		return 9;
	else
		return num % 9;
}
int main(){
	cout <<	addDigits(12765543);
	return 0;
}
