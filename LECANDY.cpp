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
        long int c;
        bool flag = true;
        scanf("%d %d",&n,&c);
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            c -= arr[i];
            if(c < 0){
                flag = false;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
