#include<cstdio>
#include<iostream>
using namespace std;

int mod;
inline int ipow(int base,int exp){
    long long int res = 1,b=base;
    while(exp){
        if(exp & 1){
            res = (res * b);
            if(res >= mod)
                res = res%mod;
        }
        exp >>= 1;
        b = (b*b);
        if(b >= mod)
            b = b % mod;
    }
    return res;
}

inline int read()
{
   register int x;
   register char c;
   while((c=getchar_unlocked())<48);
   x=c-'0';
   while((c=getchar_unlocked())>=48){x=x*10+c-'0';}
   return x;
}


int cf[100001][25];
int a[100001];
int factors[100][25];
int main(){
    int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int n,temp,cnt;
    n = read();
    //precomputation starts
    for(int i=0;i<100;i++){
        //cout << i+1 << " : ";
        temp = i+1;
        int j =0;
        for(int j=0;j<25;j++){
            cnt = 0;
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
        a[i] = read();
        for(int j=0;j<25;j++){
            cf[i][j] = factors[a[i]-1][j];
            if(i > 0)
                cf[i][j] += cf[i-1][j];
            //cout << cf[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << "done" << endl;
    int tCases;
    scanf("%d",&tCases);

    int left,right,power;
    long long int result;

    for(int t=0;t<tCases;t++){
        result = 1;
        left=read(),right=read(),mod=read();
        --left,--right;
        //cout << "done" << endl;
        for(int j=0;j<25;j++){
            power = cf[right][j];
            if(left>=1){
                power -= cf[left-1][j];
            }
            result = (result*ipow(primes[j],power));
            if(result >= mod)
                result = result % mod;
        }
        printf("%lld\n",result);
    }
    return 0;
}
