#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

set<int> sums;

void subset(vector<int> &a,int sum,int n){
    if(sum != 0)
        sums.insert(sum);
    subset(a,sum-a[n-1],n-1);
    subset(a,sum,n-1);
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        long long int sum = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum ^= a[i];
        }
        if(sum)
            printf("NO\n");
        else{
            sort(a.begin(),a.end());
            long long ans = 0;
            for(int i=1;i<a.size();i++){
                ans += a[i];
            }
            cout << ans << endl;
        }


    }
    return 0;
}
