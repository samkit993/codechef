#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        cin.ignore();
        int n;
        double sum = 0.0;
        double d;
        scanf("%d",&n);
        vector<pair<int, int> > points(n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&points[i].first,&points[i].second);
        }
        sort(points.begin(),points.end(),compare);

        for(int i=1;i<n;i++){
            d = sqrt((points[i].first-points[i-1].first)*(points[i].first-points[i-1].first) + (points[i].second-points[i-1].second)*(points[i].second-points[i-1].second) );
            sum += d;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
