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
        long long unsigned int n,k;
        cin >> n >> k;
        if(n==0)
            cout << 0 << " " << 0 << endl;
        else if(k==0)
            cout << 0 << " " << n << endl;
        else
            cout << (n/k) << " " <<  (n%k) << endl;
    }
    return 0;
}
