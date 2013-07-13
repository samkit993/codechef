#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int wd;
    float bal;
    scanf("%d %f",&wd,&bal);
    if(wd % 5 == 0 && bal-(wd + 0.50) > 0){
        bal -= (wd + 0.50);
    }
    printf("%.2f",bal);
    return 0;
}
