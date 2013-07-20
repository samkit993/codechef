#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define sqr(x) (x)*(x)
using namespace std;
bool isPrime(int n){
    if(n == 2 || n==3 || n==5 || n==7 )
        return true;

    if(n % 2==0 || n%3==0 || n%5==0 || n%7==0 )
        return false;
    for(int i=11;i<sqrt(n);i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}

int getNo1(int n,int &count){
    if(n==0)
        return count;
    int temp = 1;
    while(temp < n){
        temp = temp << 1;
    }
    if(temp != n)
    temp = temp >> 1;
    count++;
    int diff = n-temp;
    getNo1(diff,count);
}

long int getAns(int ans1,int ans0){
    int i,j;
    long int temp,sum=0;
    i = ans0;
    while(i< (ans1+ans0)){
        j = i;
        temp = 1;
        while(j>0){
            temp *= 2;
            j--;
        }
        sum += temp;
        i++;
    }
    return sum;
}

int main(){
    int tCases;
    scanf("%d",&tCases);
    int count;
    for(int t=0;t<tCases;t++){
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        long int ans;
        int a1,a0,b1,b0,ans1,ans0;
        count = 0;
        a1 = getNo1(a,count);
        //cout << a1 << endl;
        count = 0;
        b1 = getNo1(b,count);
        //cout << b1 << endl;
        a0 = n-a1;
        b0 = n-b1;
        ans1 = min(a1,b0) + min(a0,b1);
        ans0 = n-ans1;
        //cout << ans1 << " " << ans0 << endl;
        ans = getAns(ans1,ans0);
        cout << ans << endl;
    }
    return 0;
}
