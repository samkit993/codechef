#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
bool isEligible(int n){
	bool flag = false;
	while(n > 0){
		if(n % 10 == 1){
			flag = true;
			break;
		}
		n /= 10;
	}
	return flag;
}
bool isHappy(int n){
	vector<int> nums(1001, false);
	nums[0] = false;
	nums[1] = true;nums[10] = true;nums[100] = true;
	for(int i=1;i<nums.size();++i){

	}
	while(isEligible(n)){
		int newn = 0;
		while(n > 0){
			newn += ((n % 10) * (n % 10));
			n /= 10;
		}
		n = newn;
		if(n == 1)
			return true;
	}
	return false;
}
int main(){
	cout << isHappy(19);
	return 0;
}
