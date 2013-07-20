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
        int n,temp;
        vector<int> ans;
        scanf("%d",&n);
        int x=n/7;
        int flag = false;
        while(x>0){
            temp = n - x*7;
            if(temp%4==0){
                flag = true;
                break;
            }
            x--;
        }
        if(flag){
            printf("%d\n",7*x);
        }else if(n%4==0){
            printf("0\n");
        }else{
            printf("-1\n");
        }



    }
    return 0;
}
