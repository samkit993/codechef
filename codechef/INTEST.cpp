#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int n,k,count=0;
    scanf("%d %d",&n,&k);
    for(int i = n;i > 0; --i){
        long int temp;
        scanf("%ld",&temp);
        if(temp % k == 0)
            ++count;
    }
    printf("%d",count);
    return 0;
}
