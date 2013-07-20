#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;

int nCr(int n, int r){
    if(n==r || r==0)
        return 1;
    if(r == 1)
        return n;
    return nCr(n-1,r-1) + nCr(n-1,r);
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        vector<int> arr(11);
        int n;
        for(int i=0;i<11;i++)
            scanf("%d",&arr[i]);
        scanf("%d",&n);
        sort(arr.begin(),arr.end());
        int temp = arr[11-n];
        int m = count(arr.begin(),arr.end(),temp);
        int r = count(arr.begin(), arr.begin()+11-n,temp);
     //   cout << "complete " << m << " " << r << endl;
        cout << nCr(m,r) << endl;

    }
    return 0;
}
