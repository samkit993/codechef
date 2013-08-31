#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;

long long int ipow(long long int base,int exp){
        long long int res = 1;
        while(exp){
            if(exp & 1)
                res *= base;
            exp >>= 1;
            base *= base;
        }
        return res;
}

int getbase(string s){
    sort(s.begin(),s.end());
    int count = 0;
    for(int i=0;i<s.size();i++){
        while(s[i]==s[i+1]){
            i++;
        }
        count++;
    }
    if(count == 1)
        return 2;
    else
        return count;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        string s;
        cin >> s;

        int base = getbase(s);
        //cout << base << endl;
        map<char,int> mapping;
        mapping[s[0]] = 1;
        int i=0;
        while(s[i]==s[i+1]){
            i++;
        }
        mapping[s[i+1]] = 0;
        int p = 2;
        long long int ans = 0;
        for(int j=0,k=s.size()-1;j<s.size();j++,k--){
            if(mapping.find(s[j])==mapping.end()){
                mapping[s[j]] = p;
                p++;
            }
            //cout << mapping[s[j]] * ipow(base,k) << endl;
            ans += mapping[s[j]] * ipow(base,k);
        }
        cout << ans << endl;
    }
    return 0;
}
