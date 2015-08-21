#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#define sqr(x) ((x)*(x))
#define sz 32000
using namespace std;

vector<int> primes;

void show(vector<bool> &a){
    for(int i=0;i<a.size();i++){
        if(a[i]){
            cout << i << endl;
        }
    }
}
void init(){
    primes.push_back(2);
    bool prime;
    for(int i=3;i<sz;i+=2){
        prime = true;
        for(int j=0;j<primes.size();j++){
            if(i % primes[j]==0){
                prime = false;
                break;
            }
        }
        if(prime){
            primes.push_back(i);
        }
    }
}
int main(){
    int tCases;
    cin >> tCases;
    init();
    //cout << "completed " << endl;
    //show(primes);
    unsigned int i,j,k;
    bool prime;

    for(int t=0;t<tCases;t++){
        unsigned int m,n;
        cin >> m >> n;
        if(m==1)
            m++;
        if(n < 32000){
            int i=0;
            while(primes[i] < m)
                i++;
            for(;primes[i]<=n;i++){
                cout << primes[i] << endl;
            }
        }else{
            for(i=m; i<=n;i++){
                bool prime = true;
                for(j=0;primes[j]*primes[j] <= i ;j++){
                    if(i % primes[j] == 0){
                        prime = false;
                        break;
                    }
                }
                if(prime)
                    cout << i << endl;
            }
            /*cout << "starting now" << endl;
            for(k=0;k<n-m+1;k++){
                if(temp[k]){
                    //cout << (m+k) << endl;
                }
            }
            */
        }
    }
    return 0;
}
