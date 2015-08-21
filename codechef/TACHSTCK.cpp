#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int n,d,ans=0;
    cin >> n >> d;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-1;){
        if(arr[i]+d >= arr[i+1]){
            i+=2;
            ans++;
        }else{
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
