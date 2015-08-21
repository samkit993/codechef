#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int tCases;
    scanf("%d",&tCases);
    cin.ignore();
    for(int t=0;t<tCases;t++){
        string s;
        long long int ans=1;
        getline(cin,s);
        int i,j;
        for(i=0,j=s.size()-1;i<=j;i++,j--){
            if(s[i]=='?' && s[j]=='?'){
                ans *= 26;
                ans = ans % 10000009;
            }else if(s[i] == '?' || s[j] == '?'){
                //do nothing
            }else if(s[i] != s[j]){
                ans = 0;
                break;
            }
        }
        cout << (ans % 10000009) << endl;

    }
    return 0;
}
