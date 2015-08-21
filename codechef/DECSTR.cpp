#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int k;
        scanf("%d",&k);
        string ans,str;
        int temp = k;
        char c=97;
        int count = 0,i;
        while(temp > 0){
            if(temp%25==0){
                i = 25;
            }else{
                i = temp%25;
            }
            temp -= i;
            str.clear();
            while(i>=0){
                str += (c+i);
                i--;
            }
            ans += str;
        }
        cout << ans << endl;
    }
    return 0;
}
