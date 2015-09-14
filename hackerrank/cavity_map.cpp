#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
	int n;
	//freopen("input", "r", stdin);
	scanf("%d",&n);
	vector<vector<int> > m(n);
	vector<vector<char> > ans(n);
	vector<string> input(n);
	for(int i=0;i<n;++i){
		m[i].resize(n);
		ans[i].resize(n);
	}
	for(int i=0;i<n;++i){
		cin >> input[i];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			m[i][j] = (int)(input[i][j] - '0');
			//printf("%d",m[i][j]);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if((i != n-1 && j != n-1) && (i != 0 && j != 0) && m[i][j] > m[i-1][j] && m[i][j] > m[i][j-1] && m[i][j] > m[i][j+1] && m[i][j] > m[i+1][j]){ 
				ans[i][j] = 'X';
				//printf("HERE i:%d j:%d %d %c\n", i,j, m[i][j], ans[i][j]);
			}else{
				ans[i][j] = (char)(m[i][j] + '0');
				//printf("i:%d j:%d %d %c\n", i,j, m[i][j], ans[i][j]);
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%c",ans[i][j]);
		}
		cout << endl;
	}
	return 0;
}
