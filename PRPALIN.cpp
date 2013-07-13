#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if( n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
        return false;
    for(int i = 11;i<=sqrt(n);i += 2){
        if(n % i == 0)
            return false;
    }
    return true;
}

bool isPalin(int n){
    int sum = 0,rem;
    int temp = n;
    while(temp > 0){
        rem = temp%10;
        sum = (sum*10)+rem;
        temp = temp/10;
    }
    if(n == sum){
        return true;
    }
    return false;
}


int main(){
    int n;
    int sum=0, rem;
    scanf("%d",&n);
    bool flag = true;
    for(int i=n;;++i){
        if(isPalin(i)){
            if(isPrime(i)){
                cout << i;
                break;
            }
        }
    }
    return 0;
}
