#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;


int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n,mini = 1000000000,temp;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            temp = abs(arr[i]-arr[i-1]);
            if(temp < mini){
                mini = temp;
            }
        }
        cout << mini << endl;
    }
    return 0;
}
