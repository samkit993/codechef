
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        cin >> n;
        vector<int> start(n);
        vector<int> time_taken(n);
        vector<int> interval(n);
        int dist = 0,temp;

        for(int i=0;i<n;i++){
            cin >> start[i] >> time_taken[i] >> interval[i];
        }
        dist = start[0] + time_taken[0];
        for(int i=1;i<n;i++){
            temp = start[i];
            while(temp < dist ){
                temp += interval[i];
            }
            //cout << "temp - dist = " << (temp-dist);
            dist += (temp - dist);
            //cout << dist << endl;
            dist += time_taken[i];
            //cout << dist << endl;
        }
        cout << dist << endl;
    }
    return 0;
}
