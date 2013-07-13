#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int a, b;
    scanf("%d %d",&a,&b);
    int diff = a - b;
    if(diff==1)
        printf("2");
    else if(diff%2==0)
        printf("%d",diff+1);
    else
        printf("%d",diff-1);
    return 0;
}
