#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)

#define MAX  10000
using namespace std;
vector<unsigned long int> a(MAX, 0);

unsigned long int compute(unsigned long int n){
    if(n==0){
        return 0;
    }
    if(n < MAX && a[n])
        return a[n];
    unsigned long int temp;
    temp = compute(n/2) + compute(n/3) + compute(n/4);
    //cout <<  compute(n/2) << " " <<  compute(n/3) << " " <<  compute(n/4) << endl;
    if(n >= MAX){
        if(n > temp)
            return n;
        else
            return temp;
    }else{
        if(a[n]==0){
            if(n > temp){
                a[n] = n;
            }else{
                a[n] = temp;
            }
        }
        return a[n];
    }
}
int main(){
    unsigned long int n;
    while(cin >> n){
        cout << compute(n) << endl;
    }
    return 0;
}
