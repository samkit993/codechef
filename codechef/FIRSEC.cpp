#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

//globals
vector<vector<int> > graph;
vector<int> visited;
int differents=0;


void dfs(int v){
    differents++;
    visited[v]=true;
    for(vector<int>::iterator it=graph[v].begin();it!=graph[v].end();it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }
}

int main(){
    int tCases;
    cin >> tCases;
    for(int t=0;t<tCases;t++){
        int total,rel;
        cin >> total >> rel;
        graph = vector<vector <int> > (total);
        for(int i=0;i<rel;i++){
            int p,q;
            cin >> p >> q;
            graph[--p].push_back(--q);
            graph[q].push_back(p);
        }
        int result = 0;
        int selections = 1;
        visited = vector<int> (total,0);
        for(int u=0;u<total;u++){
            cout << u << " " << visited[u] << endl;
            if(visited[u]==true)
                continue;
            result++;
            differents = 0;
            dfs(u);
            selections = ((long long)differents * selections) % 1000000007;
        }
        cout << result << " " << selections << endl;
    }
    return 0;
}
