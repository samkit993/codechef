#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?a:b)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
using namespace std;


int bruteforce(int a[],int start,int n){
    if(start == n)
        return 0;
    int k;
    int mini = 1000;
    int cnt;

    for(k=start;k<n;k++){
        cnt = bruteforce(a,start,k) + bruteforce(a,k+1,n) + a[start-1]*a[n]*a[k];

        if(cnt < mini)
            mini = cnt;
    }
    return mini;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        int matrix[n];
        for(int i=0;i<n;i++){
            scanf("%d",&matrix[i]);
        }
        cout << bruteforce(matrix,1,n);
    }
    return 0;
}
