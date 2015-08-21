
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;


int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n,a,b,c;
        int count=0;
        cin >> n >> a >> b >> c;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                for(int k=0;k<=c;k++){
                    //cout << i << " " << j << " " << k << endl;
                    if(i+j+k<=n)
                        count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
