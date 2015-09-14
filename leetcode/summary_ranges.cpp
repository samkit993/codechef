#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

string itos(long long int a){
	if(a == 0)
		return "0";
	string str;	
	bool minus = (a < 0) ? true : false;
	a = (minus) ? -a : a;
	while(a > 0){
		str += (char( '0' + a % 10));
		a /= 10;
	}
	str += ((minus) ? "-" : "");
	reverse(str.begin(), str.end());
	return str;
}

vector<string> summaryRanges(vector<int> &nums){
	vector<string> ans;
	if(nums.size() == 0)
	return ans;
	int i,start = nums[0], end = 0;
	for(i=1;i<nums.size();i++){
		printf("i:%d, nums[i]:%d, nums[i-1]:%d, start:%d end:%d\n",i,nums[i], nums[i-1], start,end);
		if((long long)nums[i] - (long long)nums[i-1] > 1){
			end = nums[i-1];
			string temp = "";
			if(start == end){
				temp += itos(start);
			}else{
				temp += itos(start) ;
				temp += "->" ;
				temp += itos(end) ;
			}
			ans.push_back(temp);
			start = nums[i];
		}
	}
	end = nums[i-1];
	string temp = "";
	if(start == end){
		cout << temp << endl;
		temp += itos(start);
	}else{
		temp += itos(start) ;
		temp += "->" ;
		temp += itos(end) ;
		cout << temp << endl;
	}
	ans.push_back(temp);
	
	return ans;
}
int main(){
	cout << itos(-2147483647) << endl;
	int arr[5] = {-2147483648,-2147483647,2147483647,  6,7};
	vector<int> a(arr, arr+5);
	vector<string> ans = summaryRanges(a);
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}
