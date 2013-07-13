#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

void decompose( int n, bool &plus,ofstream &out){
    //decomposing operation
    int t=2,power=0;
    while(t<=n){
        t = t << 1;
        ++power;
    }
    t = t >> 1;

    //printing operation
    if(plus){
        out << "+";
        plus = false;
    }
    if(t==1){
        out << "2(0)";
    } else if(t==2){
        out << "2";
    } else {
        out << "2(";
        decompose(power,plus,out);
        out << ")";
    }
    if(!plus)
        plus = true;

    //decomposing remaining part
    if(n!=t)
    decompose(n-t,plus,out);
}
int main(){
    bool check = 0;
    ofstream myfile("output.txt");
    int arr[7] = {137,1315,73,136,255,1384,16385};
    for(int i=0;i<7;++i){
        check = 0;
        myfile << arr[i] << "=";
        decompose(arr[i],check,myfile);
        myfile << endl;
    }
    return 0;
}
