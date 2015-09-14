#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
vector<vector<int> > generate(int numRows) {
//(n,r) = (n-1, r-1) + (n-1,r)
	vector<vector<int> > ans;
	if(numRows == 0)
		return ans;
	vector<int> temp;
	temp.push_back(1); //n=0,r=0
	ans.push_back(temp);
	if(numRows == 1)
		return ans;
	temp.push_back(1); //n=1,r=0; n=1,r=1
	ans.push_back(temp)
	for(int i=2;i<numRows;++i){
		temp.clear();
		for(int j=0;j<i+1;++j){
			if(j==0)
				temp.push_back(ans[i-1][j]);
			else if(j >= ans[i-1].size())
				temp.push_back(ans[i-1][j-1]);
			else
				temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
		}
		ans.push_back(temp);
	}
	return ans;
}
int main(){
	return 0;
}
