#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

long long ipow(int base, int power){
	unsigned long long ans = 1;
 	while( power != 0){	
		if( power & 1 == 1)
			ans *= base;
		base *= base; 
		power >>= 1;
	}
	return ans;
}
long long stoi(string str){
	bool minus = false;
	if(str[0] == '-'){
		minus = true;
		str = str.substr(1,str.size());
	}
	long long ans = 0; 
	int n = str.size();
	for(int i=n-1;i>=0;--i){
		ans += ((int)(str[i] - '0'))*ipow(10, n-1-i);
	}
	return ans;
}
void computePermute(string done, string rem, vector<string> &permutations){
	if(rem == "" || done.size() == 3){
		permutations.push_back(done);
	}else{
		for(int i=0;i<rem.size();++i){
			string new_done = done + rem[i];
			string new_rem = rem.substr(0,i) + rem.substr(i+1);
			computePermute(new_done, new_rem, permutations);
		}
	}
}
int main(){
	int tCases;
	scanf("%d", &tCases);
	for(int t=0;t<tCases;++t){
		string n;
		cin >> n;
		bool found = false;
		vector<string> permutes;
		computePermute("",n, permutes); 
		for(int i=0;i<permutes.size();++i){
			if(stoi(permutes[i]) % 8 == 0){
				cout << "YES" << endl;
				found = true;
				break;
			}
		}
		if(!found){
			cout << "NO" << endl;
		}
	}
	return 0;
}
