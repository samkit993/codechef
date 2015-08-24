#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
	int xored = 0;
	for(int i=0;i<nums.size();++i){
		xored ^= nums[i];
	}
	return xored;
}
int main(){
	int arr[10] = {1, 2, 3, 4,  6, 1, 2, 3, 4};
	vector<int> nums(arr, arr+9);
	cout << singleNumber(nums);
	return 0;
}
