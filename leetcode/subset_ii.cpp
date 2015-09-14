#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
void computeSubsets(vector<int>& rem, vector<int>& done, vector<vector<int> > &subsets){
	if(rem.empty()){
		subsets.push_back(done);
		return;
	}
	vector<int> new_rem=rem, new_done=done;
	new_rem.erase(new_rem.begin());
	computeSubsets(new_rem,new_done,subsets);
	new_done.push_back(rem[0]);
	computeSubsets(new_rem,new_done,subsets);
}

vector<vector<int> > subsets(vector<int>& nums){
	vector<int> done;
	vector<vector<int> > ans;
	computeSubsets(nums, done, ans);
	return ans;
}
int main(){
	int a[3] = {1,2,3};
	vector<int> arr(a, a+3), remaining;
	vector<vector<int> > ans;
	ans = subsets(arr);
	for(int i=0;i<ans.size();++i){
		for(int j=0;j<ans[i].size();++j){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
