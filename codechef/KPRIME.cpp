#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
vector<int> primelist;

bool isPrime(int n){
    if(n == 2 || n==3 || n==5 || n==7 )
        return true;

    if(n % 2==0 || n%3==0 || n%5==0 || n%7==0 )
        return false;
    for(int i=11;i<sqrt(n);i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
int getCount(int n){
    primelist[0] = 2;
    int count=0;
    int i,j;
    for(i=0;i<primelist.size();++i){
        if(n % primelist[i] == 0)
            ++count;
    }
    j = primelist[primelist.size()-1];
    if(n==1000){
        for(int t=0;t<primelist.size();++t)
        cout << primelist[t] << "  ";
    }
    while(j < n){
        if(j%2==0)
            j++;
        else
            j+=2;
        if(isPrime(j)){
            primelist[i] = j;
            //cout <<" in while "<< " j = " << j<< " i = "  << i << " " << primelist[i] << endl;
            if(n % j == 0)
                ++count;
            i++;
        }
    }
    return count;
}

int* fermat(int n){
    int a;
    a = ceil(sqrt(n));
    b = a*a - n;
    while(sqrt(b)==ceil(sqrt(b))){
        b = b+1;
    }
    int ans[2];
    ans[0] = a;
    ans[1] = b;
    return ans;
}

int main(){
    int tCases;
    int a,b,k;
    int p;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;++t){
        int kcount=0;
        scanf("%d %d %d",&a,&b,&k);
        p = a;
        for(int p=a;p<=b;++p){
            if(getCount(p)== k)
                ++kcount;
        }
        printf("%d\n",kcount);
    }
    return 0;
}
