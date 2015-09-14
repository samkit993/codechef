#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

string convert(string s, int numRows){
	string ans="";
	vector<int> offsets(numRows,0);
	vector<bool> printed(s.size(), false);
	for(int i=0;i<numRows;++i){
		int prev = 0;
		if(i % 2 == 0){
			offsets[i] = numRows+1;	
		}else{
			offsets[i] = (prev + 1)%(numRows-1);	
			if(offsets[i] == 0 || offsets[i] == 1)
				offsets[i] = 2;
			prev = offsets[i];
		}
		for(int j=i;j<s.size();j+=offsets[i]){
			printf("i:%d, offsets[i]:%d, j:%d, s[j]:%c\n",i, offsets[i],j,s[j]);
			if(!printed[j]){
				printf("Inside i:%d, offsets[i]:%d, j:%d, s[j]:%c\n",i, offsets[i],j,s[j]);
				printed[j] = true;
				ans += s[j];
			}
		}
	}
	return ans;
}
int main(){
	cout << convert("AB", 1);
	return 0;
}
