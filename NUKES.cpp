#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;
string itoc(int n){
    stringstream s;
    s << n;
    return s.str();
}

int main(){
    long int a;
    int n,k;
    scanf("%ld %d %d",&a,&n,&k);
    //cout << a << " " << " " << n << " "  << k << endl;
    string ans;
    int count = k;
    while((a>0) && (count>0) ){
        int temp;
        //cout << "a = " << a << " " << ans << endl;
        if( a >= (n+1)){
            temp = a % (n+1);
            a = a/(n+1);
        }else{
            temp = a;
            a= 0;
        }
        ans += itoc(temp);
        ans += " ";
        --count;
    }
    if(count > 0){
        for(int i=0;i< count;++i){
            ans += '0';
            ans += ' ';
        }
    }
    cout << ans;
    return 0;
}
