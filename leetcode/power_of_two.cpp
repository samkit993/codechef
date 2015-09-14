#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
bool isPowerOfTwo(int n){
	if(n == 0)
		return false;
	while(n % 2 == 0){
		n /= 2;
	}
	return (n == 1) ? true: false;
}
int main(){
	cout << isPowerOfTwo(0);
	return 0;
}
