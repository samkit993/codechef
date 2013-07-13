#include<iostream>
#include<cstdio>
using namespace std;void dec( int n,bool &p){int t=2;int z=0;while(t<=n){t=t << 1;++z;}t=t >> 1;if(p){printf("+");p=0;}if(t==1){printf("2(0)");} else if(t==2){printf("2");} else {printf("2(");dec(z,p);printf(")");}if(!p)p =1;if(n!=t)dec(n-t,p);}
int main(){bool c;int arr[7]={137,1315,73,136,255,1384,16385};for(int i=0;i<7;++i){c=0;cout << arr[i]<<"=";dec(arr[i],c);cout << endl;}return 0;}
