#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int trailingZeroes(int n){
	int fives = 0;
	for(long int i=5;i<=n;i*=5){
		fives += int(n/i);
	}
	return fives;
}
int main(){
	cout << trailingZeroes(1808548329);
	return 0;
}
