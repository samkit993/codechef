#include<iostream>
#include<cstdio>
using namespace std;

int findMin(int a[],int size){
    int min = 1000;
    for(int i=0;i<size;++i){
        if(a[i] < min)
            min = a[i];
    }
    return min;
}
int gcd(int a[],int size){
    int temp = findMin(a,size);
    for(int i=temp;i>0;--i){
        bool flag = true;
        for(int j=0;j<size;++j){
            if(a[j] % i != 0){
                flag = false;
            }
        }
        if(flag)
            return i;
    }
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;++t){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        int gcd1 = gcd(arr,n);
        for(int i=0;i<n;++i){
            printf("%d ",arr[i]/gcd1);
        }
        printf("\n");

    }
    return 0;
}
