#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector<int> majorityElement(vector<int> &nums){
	vector<int> ans;
	map<int,int> cnt;
	for(int i=0;i<nums.size();i++){
		if(cnt.find(nums[i]) == cnt.end())
			cnt[nums[i]] = 1;
		else
			cnt[nums[i]] += 1;
	}
	int n3 = nums.size()/3;
	for(map<int,int>::iterator it=cnt.begin(); it!=cnt.end();it++){
		if(it->second >= n3)
			ans.push_back(it->first);
	}
	return ans;
}
int main(){
	return 0;
}
