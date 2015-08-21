
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int t=0;t<n;t++){
        cin >> a[t];
    }
    long long int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            sum += (a[i] & a[j]);

        }
    }
    cout << sum << endl;
    return 0;
}
