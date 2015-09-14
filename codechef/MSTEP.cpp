#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;

vector<int> bfs(int start, vector<vector<int> > &adjList){
	queue<int> q;
	vector<int> visited(adjList.size(), 0), prev(adjList.size(), -1);
	visited[0] = true;//dummy node
	q.push(start);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		visited[temp] = 1;
		for(int j=0;j<adjList[temp].size();++j){
			if(!visited[adjList[temp][j]]){
				prev[adjList[temp][j]] = temp;
				q.push(adjList[temp][j]);
			}
		}
	}
	return prev;
}
int abs(int x){
	return (x < 0) ? -x : x;
}
int main(){
	int tCases;
	scanf("%d", &tCases);
	for(int t=0;t<tCases;++t){
		int n;
		scanf("%d", &n);
		int mat[n][n];
		map<int, vector<int> > revmap;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
				revmap[mat[i][j]].push_back(i);
				revmap[mat[i][j]].push_back(j);
			}
		}
		int sum = 0;
		for(int i=2;i<=n*n;i++){
			int temp = abs(revmap[i][0] - revmap[i-1][0]) + abs(revmap[i][1] - revmap[i-1][1]);
			//printf("Distance between %d and %d : %d\n",i,i-1, temp);
			sum += temp;
		}
		printf("%d\n", sum);
	}
	return 0;
}
