#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
string convertToTitle(int n){
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ans = "";
	while(n >= 1){
		n--;
		ans = alpha[n % 26 ] + ans;
		n = n/26;
	}
	return ans;
}
int main(){
	for(int i=1;i<=55;i++)
	cout << i << " " << convertToTitle(i) << endl;;
	return 0;
}
