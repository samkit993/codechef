#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int removeDuplicates(vector<int> &nums){
	cout << nums.size();
	vector<int> remove;
	int cnt = 0, val;
	for(int i=0;i<nums.size();i++){
		if(cnt == 0){
			val = nums[i];
			cnt++;
		}else if(nums[i] == val){
			cnt++;
			if(cnt > 2){
				remove.push_back(i);
			}
		}
		if(i < nums.size()-1 && nums[i+1] != val)
			cnt = 0;
		printf("i:%d nums[i]:%d cnt:%d val:%d\n", i, nums[i], cnt,val);
	}
	for(int i=0;i<remove.size();i++){
		printf("remove[i]:%d i:%d\n",remove[i], i);
		nums.erase(nums.begin() + remove[i] - i);	
	}
	return nums.size();
}
int main(){
	int arr[6] = {1,1,1,2,2,3}, ans;
	vector<int> a(arr, arr+6);
	ans = removeDuplicates(a);
	for(int i=0;i<a.size();i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
