#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>

using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int p=0;p<tCases;++p){
        int n;
        scanf("%d",&n);
        if(n%2==1)
            printf("BOB\n");
        else
            printf("ALICE\n");
    }
    return 0;
}
