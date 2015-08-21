#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

long long int combinations(int n, int r){
    if(n==r || r==0)
        return 1;
    if(r > n/2){
        r = (n-r);
    }
    long long int ans=1;
    for(int i=n,j=1;j<=r;i--,j++){
        //cout << i << "  " << j << endl;
        ans *=i;
        ans /= j;
    }
    return ans;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n, r;
        cin >> n >> r;
        cout << combinations(n-1,r-1) << endl;
    }
    return 0;
}
