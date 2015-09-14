#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

void dfs(int j, vector<vector<int> > &adjlist, vector<int> &visited, int &ncomp){
	visited[j] = true;
	ncomp++;
	cout << ncomp << endl;
	for(int i=0;i<adjlist[j].size();j++){
		if(!visited[adjlist[j][i]]){
			dfs(adjlist[j][i], adjlist, visited, ncomp);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	vector<int> vertices(2*n);
	vector<vector<int> > adjlist(2*n);
	vector<int> visited(2*n,true);
	for(int i=0;i<n;i++){
		int temp1, temp2;
		scanf("%d %d",&temp1, &temp2);
		printf("%d %d\n",temp1-1, temp2-1);
		visited[temp1-1] = false;
		visited[temp2-1] = false;
		adjlist[temp1-1].push_back(temp2-1);
		adjlist[temp2-1].push_back(temp1-1);
	}
	for(int i=0;i<2*n;i++){
		for(int j=0;j<adjlist.size();j++){
			cout << adjlist[i][j] << " ";
		}
		cout << endl;
	}
	vector<int> comp;
	for(int i=0;i<2*n;i++){
		if(!visited[i]){
			int temp=0;
			dfs(i, adjlist, visited, temp);
			cout << temp << endl;
			comp.push_back(temp);
		}
	}
	sort(comp.begin(), comp.end());
	cout << comp[0] << " " << comp[comp.size()-1];
	return 0;
}

