#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target){
	vector<int> ans;
	int start = 0, end = nums.size() - 1 ;
	int mid = nums.size()/2;
	//cout << target << endl;
	while(nums[mid] != target && start < end){
		if(nums[mid] < target){
			start = mid + 1;
		}else{
			end = mid-1;
		}
		mid = (start + end)/2;
	}
	if(nums[mid] != target){
		ans.push_back(-1);
		ans.push_back(-1);
		return ans;
	}
	//printf("mid:%d nums[mid]:%d\n", mid, nums[mid]);
	while(mid > 0 && nums[mid] == nums[mid-1])
		mid--;
	ans.push_back(mid);
	while(nums[mid] == nums[mid+1])
		mid += 1;
	ans.push_back(mid);
	return ans;
}
int main(){
	int arr[21] = {0,0,0,0,2,2,3,3,4,4,5,5,5,6,7,7,8,9,9,9,10};
	vector<int> a(arr, arr+21), ans;
	ans = searchRange(a,10);
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
