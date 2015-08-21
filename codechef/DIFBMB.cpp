#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
vector<int> primes;
void precompute(){
    primes.push_back(2);
    for(int i=3;i<=104729;i+=2){
        bool prime = true;
        for(int j=0;j<primes.size();j++){
            if(i % primes[j] == 0){
                prime = false;
                break;
            }
        }
        if(prime)
            primes.push_back(i);
    }
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    precompute();
    for(int t=0;t<tCases;t++){
        int a,b;
        cin >> a >> b;
        int k=0,cnt=0;
        while(primes[k] < a)
            k++;
        for(;primes[k]<=b;k++){
            //cout << primes[k] << " ";
            if(primes[k] % 4 == 1){
                ++cnt;
            }
        }
        if(a == 2 || a==1)
            ++cnt;
        cout << cnt << endl;
    }
    return 0;
}
