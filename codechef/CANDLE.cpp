#include<iostream>
#include<cstdio>
#include<cmath>
int power(int base, int pow){
    int mul = 1;
    for(int i=0;i<pow;++i){
        mul = mul * base;
    }
    return mul;
}
using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;++t){
        int arr[10];
        for(int i=0;i<10;++i){
            scanf("%d",&arr[i]);
        }
        //cout << "complete";
        bool flag = false;
        int ans=1111111111, ans0=1111111111;
        for(int i=0;i<9;++i){
            for(int j=0;j<10;++j){
                if(arr[j] == 0){
                    if(j==0)
                        ans0 = 10;
                    else{
                        ans = j;
                        flag = true;
                        break;
                    }
                }
                if(arr[j] == i){
                    if(j==0)
                        ans0 = power(10,i+1);
                    else{
                        int value = j;
                        for(int k=0;k<i;++k){
                            value = (10 * value) + j;
                        }
                        ans = value;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        if(ans0 < ans)
            printf("%d\n",ans0);
        else
            printf("%d\n",ans);
    }
    return 0;
}
