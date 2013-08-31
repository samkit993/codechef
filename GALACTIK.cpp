//Using dfs
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
#define INF 1000000000
using namespace std;

vector<vector<int > > planets;
vector<int> visited;
vector<int> tax;
int mini = INF;

void dfs(int v){
    //cout << mini << endl;
    if(tax[v] < mini && tax[v] >= 0){
        mini = tax[v];
    }
    visited[v] = true;
    for(vector<int>::iterator it=planets[v].begin();it!=planets[v].end();it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }
}
int main(){
        int n,m;
        cin >> n >> m;
        planets = vector<vector<int > >(n);
        for(int i=0;i<m;i++){
            int p,q;
            cin >> p >> q;
            p--,q--;
            planets[p].push_back(q);
            planets[q].push_back(p);
        }
        tax = vector<int>(n);
        for(int i=0;i<n;i++){
            cin >> tax[i];
        }

        int result = 0;
        visited = vector<int> (n,false);
        int components = 0;
        int global_min = INF;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(visited[i]==true)
                continue;
            components++;
            mini = INF;
            dfs(i);
            if(mini == INF){
                result = -1;
                flag = true;
                break;
            }
            if(mini < global_min)
                global_min = mini;
            //cout << " r = " << result << endl;
            result += mini;
        }
        if(components==1){
            result = 0;
        }else if(components > 2 && !flag){
            components -= 2;
            result += components*global_min;
        }
        cout << result << endl;
    return 0;
}
