#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
using namespace std;
int majorityElement(vector<int> &nums){
	map<int,int> cnt;
	for(int i=0;i<nums.size();i++){
		if(cnt.find(nums[i]) == cnt.end())
			cnt[nums[i]] = 1;
		else
			cnt[nums[i]] += 1;
	}
	int n2 = nums.size()/2;
	for(map<int,int>::iterator it=cnt.begin(); it!=cnt.end();it++){
		if(it->second >= n2)
			return it->first;
	}
}
int main(){
	return 0;
}
