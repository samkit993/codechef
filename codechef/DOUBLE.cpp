#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int p=0;p<tCases;++p){
        int n;
        scanf("%d",&n);
        if(n % 2 == 0)
            printf("%d\n",n);
        else
            printf("%d\n",n-1);
    }
    return 0;
}
