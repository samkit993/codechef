#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int solve(vector<int> &pieces){
	while(true){
		vector<int>::iterator lowest = min_element(pieces.begin(), pieces.end());
		int m = pieces.size();
		if(*lowest == m-2){
			return m-2;
		}else if(*lowest > m-2){
			return m-1;
		}else{
			int temp = *lowest;
			pieces.erase(lowest);
			*min_element(pieces.begin(), pieces.end()) += temp;
		}
	}
}
int main(){
	int tCases;
	scanf("%d", &tCases);
	for(int t=0;t<tCases;++t){
		int n,m;
		scanf("%d %d", &n,&m);
		vector<int> pieces(m);
		for(int i=0;i<m;i++){
			scanf("%d",&pieces[i]);
		}
		cout << solve(pieces) << endl;
	}
	return 0;
}
