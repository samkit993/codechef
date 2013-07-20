
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int ans = 1;
        int curr_min = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] < curr_min){
                ans++;
                curr_min = arr[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
