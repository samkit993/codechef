#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;
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
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        vector<int> arr(n),dep(n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&dep[i]);
        int first,last;
        first = *min_element(arr.begin(),arr.end());
        last = *max_element(arr.begin(),arr.end());
        //cout << first <<" "<< last << endl;
        int count=0;
        int max = 0;
        for(int i=first;i<=last;i++){
            count  = 0;
            for(int p=0;p<n;p++){
                if(arr[p] <= i && dep[p] > i )
                    count++;
            }
            if(count > max)
                max = count;
        }
        cout << max << endl;
    }
    return 0;
}
