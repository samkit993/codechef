#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
struct num{
	int val;
	int loc;
	num(int _val, int _loc) : val(_val), loc(_loc) {}
};
bool compareNum(num a, num b){
	return a.val < b.val;
}
vector<int> twoSum(vector<int>& nums, int target) {
	vector<num> struct_nums;
	for(int i=0;i<nums.size();++i){
		num temp(nums[i], i+1);
		struct_nums.push_back(temp);
	}
	sort(struct_nums.begin(), struct_nums.end(), compareNum);
	int start=0, end=nums.size()-1, lans, hans;
	while(start < end){
		if(struct_nums[start].val + struct_nums[end].val == target){
			lans = (struct_nums[start].loc < struct_nums[end].loc ) ? struct_nums[start].loc : struct_nums[end].loc;
			hans = (struct_nums[start].loc > struct_nums[end].loc ) ? struct_nums[start].loc : struct_nums[end].loc;
			//printf("low idx:%d val:%d AND high idx:%d val:%d\n", start, end,struct_nums[start].loc, struct_nums[end].loc);
			vector<int> ans;
			ans.push_back(lans);ans.push_back(hans);
			return ans;
		}else if(struct_nums[start].val + struct_nums[end].val < target){
			start++;
		}else{
			end--;
		}
	}
}
int main(){
	int arr[6] = { 1,2,5, 9 , 10, 7};
	vector<int> nums(arr, arr+6), ans;
	ans = twoSum(nums, 17);
	cout << "Ans size " << ans.size() << endl;
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << " " ;
	}
	return 0;
}
