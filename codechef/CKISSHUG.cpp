#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

long long ipow(long long base ,long long exp){
        long long res = 1;
        while(exp){
            if(exp & 1)
                res = (res*base)%1000000007;
            exp >>= 1;
            base = (base*base)%1000000007;
        }
        return res;
}


long long getAns(long long n){
    if(n==1){
        return 2;
    }else if(n==0){
        return 0;
    }
    else{
        if(n%2==0){
            return (ipow(2,n/2)*3)%1000000007-2;
        }else{
            return (ipow(2,(n+1)/2)*2)%1000000007  - 2;
        }
    }
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        long long n;
        cin >> n;
        cout << getAns(n) << endl;
    }
    return 0;
}
