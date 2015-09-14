#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
void computeSubsetSum(vector<int>& arr, int currSum, int maxSum){
	if(arr.empty()){
		if(currSum > maxSum)
			maxSum = currSum;
		return;
	}
	int temp = arr[0]; 
	cout << temp << " " << currSum << endl;
	arr.erase(arr.begin());
	computeSubsetSum(arr, currSum + temp ,maxSum);
	computeSubsetSum(arr, currSum, maxSum);
}

int maxSubArray(vector<int>& nums){
	int ans = 0, currSum = 0;
	computeSubsetSum(nums,currSum , ans);
	return ans;
}
int main(){
	int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> arr(a, a+9);
	int ans;
	ans = maxSubArray(arr);
	cout << ans << endl;
	return 0;
}
