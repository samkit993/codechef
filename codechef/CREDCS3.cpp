#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

const int mod = 1000000007;
long long int nCr(int n,int r){
    if(n==r)
        return 1;
    if(r == 1){
        return n;
    }
    long long int ans = 1;

    for(int i=n,j=0;j<r;i--,j++){
        ans *= i;
        ans /= j+1;
    }
    return ans;
}
long long int nPr(int n,int r){
    if(n==r)
        return 1;
    long long int ans = 1;
    for(int i=n;i>r;i--){
        ans *= i;
        if(ans >= mod)
            ans = ans % mod;
    }
    return ans;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        long long int ans=0;
        for(int i=0;i<n;i++){
            cout << nPr(n,i) << endl;
            ans += nPr(n,i);
            if(ans >= mod)
                ans = ans % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
