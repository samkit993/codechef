#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	cout << k << endl;
	if(k==0)
		return false;
	map<int,int> cnt;	
	map<int, vector<int> > revcnt, mapping;
	for(int i=0;i<nums.size();i++){
		mapping[nums[i]].push_back(i);
		if(cnt.find(nums[i]) == cnt.end())
			cnt[nums[i]] = 1;
		else
			cnt[nums[i]] += 1;
	}

	for(map<int,vector<int> >::iterator it = mapping.begin(); it != mapping.end(); it++){
		for(int i=0;i<it->second.size();i++){
			for(int j=i+1;j<it->second.size();j++){
				int temp = it->second[i] - it->second[j];
				temp = (temp < 0)? -temp: temp;
				printf("start:%d end:%d diff:%d k=%d\n",it->second[i], it->second[j], temp, k);
				if(temp <= k)
					return true;
			}
		}
	}

	return false;
}
int main(){
	int arr[100] = {1,10,5,5,6,6,4,10,5,4,9,4,9,6,5,9,6,3,6,5,6,7,7,4,9,9,10,5,8,1,8,3,2,7,5,10,1,8,5,8,4,3,6,4,9,4,2,8,3,2,2,1,5,6,3,2,6,1,8,6,2,9,1,4,5,10,8,5,10,5,10,1,4,8,3,6,4,10,9,1,1,1,2,2,9,6,6,8,1,9,2,5,5,2,1,8,5,2,3,10};
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(1);
	cout << containsNearbyDuplicate(a, 2);
	return 0;
}
