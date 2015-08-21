#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;
const int H = 1;
const int T = 2;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int g;
        cin >> g;
        while(g > 0){
            int i,n,q;
            cin >> i >> n >> q;
            int heads,tails;
            if(n%2==0){
                heads = tails = n/2;
            }else{
                if(i==H){
                    tails = n/2 + 1;
                    heads = n - tails;
                }else{
                    heads = n/2 + 1;
                    tails = n-heads;
                }
            }
            cout << (q==H ? heads : tails ) << endl;
            g--;
        }
    }
    return 0;
}
