#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
vector<int> singleNumber(vector<int>& nums) {
	int xored = 0;
	for(int i=0;i<nums.size();++i){
		xored ^= nums[i];
	}
	int lastbit = ( xored & (xored - 1) ) ^ xored, ansa = 0, ansb = 0;
	for(int i=0;i<nums.size();++i){
		if( nums[i] & lastbit )
			ansa ^= nums[i];
		else
			ansb ^= nums[i];
	}
	vector<int> ans;
	ans.push_back(ansa);
	ans.push_back(ansb);
	return ans;

}
int main(){
	int arr[10] = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4};
	vector<int> nums(arr, arr+10), ans;
	ans = singleNumber(nums);
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << " ";
	}
	return 0;
}
