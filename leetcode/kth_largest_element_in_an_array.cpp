#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	if(k == 1)
		return nums[0];
	sort(nums.begin(), nums.end());
	int cnt = 1;
	for(int i=nums.size()-1;i>=0;i++){
		if(nums[i] != nums[i-1])
			cnt++;
		if(cnt == k)
			return nums[i];
	}
}
int main(){
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(1);
	cout << findKthLargest(arr,2);
	return 0;
}
