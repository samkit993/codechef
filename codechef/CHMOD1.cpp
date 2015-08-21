#include<cstdio>
#include<iostream>
using namespace std;

long long int mod;
inline int ipow(int base,int exp){
    long long int res = 1,b=base;
    while(exp){
        if(exp & 1)
            res = (res * b)%mod;
            exp >>= 1;
            b = (b*b)%mod;
    }
    return res;
}


int main(){
    int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int n;
    cin >> n;
    int a[n];
    int cf[n][25];
    int factors[100][25];
    //precomputation starts
    for(int i=0;i<100;i++){
        //cout << i+1 << " : ";
        int temp = i+1;
        int j =0;
        for(int j=0;j<25;j++){
            int cnt = 0;
            while(temp % primes[j]==0){
                cnt++;
                temp /= primes[j];
            }
            factors[i][j] = cnt;
            //cout << factors[i][j] << " ";
        }
        //cout << endl;
    }
    //precomputation ends;
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;j<25;j++){
            if(i==0){
                cf[i][j] = factors[a[i]-1][j];
            }else{
                cf[i][j] = cf[i-1][j];
                cf[i][j] += factors[a[i]-1][j];
            }
            //cout << cf[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << "done" << endl;
    int tCases;
    cin >> tCases;
    for(int t=0;t<tCases;t++){
        int l,r;
        cin >> l >> r >> mod;
        //cout << "done" << endl;
        long long result=1;
        int power;
        for(int j=0;j<25;j++){
            if(l==1){
                power = cf[r-1][j];
            }else{
                power = cf[r-1][j] - cf[l-2][j];
            }
            result = (result*ipow(primes[j],power))%mod;
        }
        cout << result << endl;
    }
    return 0;
}
