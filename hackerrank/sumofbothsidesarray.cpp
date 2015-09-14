#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
	int tCases;
	scanf("%d",&tCases);
	for(int t=0;t<tCases;++t){
		int n;
		scanf("%d",&n);
		vector<int> arr(n);
		vector<long long int> lsum(n,0), rsum(n);
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
			if(i == 0)
				lsum[i] = arr[i];
			else
				lsum[i] = lsum[i-1] + arr[i];
		}
		rsum[n-1] = arr[n-1];
		for(int i=n-2;i>=0;--i){
			rsum[i] = rsum[i+1] + arr[i];
		}
		int ridx = n-1, lidx = 0;	
		bool found = false;
		for(int i=1;i<n-1;++i){
			if(lsum[i-1] == rsum[i+1]){
				found = true;
				break;
			}
		}
		if(found)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
