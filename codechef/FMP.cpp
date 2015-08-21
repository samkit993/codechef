#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n,hq1,hq2;
        cin >> n >> hq1 >> hq2;
        vector<vector<int > > graph(n);
        int temp;
        hq1--,hq2--;
        for(int i=0;i<n;i++){
            if(i==hq1)
                continue;
            cin >> temp;
            graph[i].push_back(--temp);
            graph[temp].push_back(i);
        }
        vector<int> ans(n);
        queue<int> q;
        q.push(hq2);
        vector<bool> visited(n,false);
        visited[hq2] = true;
        ans[hq2] = -1;

        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(size_t i=0;i<graph[v].size();i++){
                int to = graph[v][i];
                if(!visited[to]){
                    visited[to] = true;
                    q.push(to);
                    ans[to] = v;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i==hq2)
                continue;
            cout << ans[i]+1 << " ";
        }

    }
    return 0;
}
