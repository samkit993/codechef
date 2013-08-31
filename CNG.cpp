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
        long long int c,d;
        cin >> c >> d;
        long long int ans = c*d - (c+d);
        cout << ans << endl;
    }
    return 0;
}
