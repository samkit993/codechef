#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int ipow(int b,int p){
	int ans = 1;
	while(p > 0){
		if(p & 1)
			ans *= b;
		b *= b;
		p >>= 1;
	}
	return ans;
}
int titleNumber(string s){
	int ans = 0, n = s.size();
	for(int i=0;i<n;++i){
		ans = ((int)(s[i] - 'A') + 1) + ans*26;
		//printf("s[i]:%c ans:%d\n",s[i],ans);
	}
	return ans;
}
int main(){
	cout << ipow(26,2) << endl;
	cout << titleNumber("AAA")<< endl;
	return 0;
}
