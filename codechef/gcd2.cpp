#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int mod(int m, string& str){
    int temp = 0;
    int digit;
    for(int i=0;i<str.size();i++){
        digit = (temp*10) + str[i]-'0';
        temp = digit % m;
    }
    return temp;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int a;
        string b;
        int bb;
        cin >> a >> b;
        if(a==0)
            cout << b << endl;
        else{
             bb = mod(a,b);
             cout << gcd(a,bb) << endl;
        }
    }
    return 0;
}
