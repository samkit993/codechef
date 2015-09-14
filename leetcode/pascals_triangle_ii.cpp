#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
vector<int> getRow(int rowIndex) {
//(n,r) = (n-1, r-1) + (n-1,r)
	vector<int> temp1,temp2;
	temp2.push_back(1); //n=0,r=0
	if(rowIndex+1 == 1)
		return temp2;
	temp2.push_back(1); //n=1,r=0; n=1,r=1
	for(int i=2;i<rowIndex+1;++i){
		temp1 = temp2;
		temp2.clear();
		for(int j=0;j<i+1;++j){
			if(j==0)
				temp2.push_back(temp1[j]);
			else if(j >= temp1.size())
				temp2.push_back(temp1[j-1]);
			else
				temp2.push_back(temp1[j-1] + temp1[j]);
		}
	}
	return temp2;
}
int main(){
	return 0;
}
