#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums){
	vector<int> ans(nums.size(), 1);
	int temp = 1;
	for(int i=0;i<nums.size()-1;++i){
		temp *= nums[i];
		ans[i+1] *= temp;	
	}
	temp = 1;
	for(int i=nums.size()-1;i>0;--i){
		temp *= nums[i];
		ans[i-1] *= temp ;
	}
	return ans;
}
int main(){
	int arr[5] = { 3,4,5,6,7};
	vector<int> a(arr, arr+5);
	vector<int> ans = tempExceptSelf(a);
	for(int i=0;i<ans.size();++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
