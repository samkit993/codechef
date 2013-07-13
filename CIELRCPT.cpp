#include<iostream>
#include<cstdio>
using namespace std;
void divide(int n,int &div){
    int count = 0;
    int mul = 1;
    while(mul < n){
        mul = mul << 1;
        cout << mul;
        count++;
    }
    mul = mul >> 1;
    cout << mul << endl;
    count--;
    int diff = n - mul;
    div++;
    //if(diff > 0)
        //divide(diff, div);
}
int main(){
    int n;
    scanf("%d",&n);
    int ans = 0;
    divide(15,ans);
    //cout << ans;
    return 0;

}
