#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int removeElement(vector<int> &nums, int val){
	vector<int> remove;
	for(int i=0;i<nums.size();i++){
		if(nums[i] == val){
			remove.push_back(i);
		}
	}
	for(int i=0;i<remove.size();i++){
		printf("remove[i]:%d i:%d\n",remove[i], i);
		nums.erase(nums.begin() + remove[i] - i);	
	}
	return nums.size();
}
int main(){
	int arr[5] = {1,2,2,2,1}, ans;
	vector<int> a(arr, arr+5);
	ans = removeElement(a,2);
	for(int i=0;i<a.size();i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
