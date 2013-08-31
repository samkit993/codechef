#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int tCases;
    cin >> tCases;
    for(int t=0;t<tCases;t++){
        int j;
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        int count=0;
        for(int i=0;i<s.size();){
            j=0;
            while(s[i]==s[i+j]){
                j++;
            }
            if(j%2==0){
                count += j/2;
            }else{
                count += j/2 + 1;
            }
            i += j;
        }
        cout << count << endl;
    }
    return 0;
}