#include<iostream>
#include<cstdio>
using namespace std;
void divide(int n,int &div){
    if(n==0)
        return;
    int count = 0;
    int mul = 1;
    while(mul <= n && mul <=2048){
        mul = mul << 1;
        count++;
    }
    if(mul != n || mul>2048){
        mul = mul >> 1;
        count--;
    }
    div++;
    if(mul != 0){
        int diff = n - mul;
        if(diff >=  1){
            //cout << div << endl;
            divide(diff, div);
        }
    }
    return;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        int ans = 0;
        divide(n,ans);
        cout << ans << endl;
    }
    return 0;

}
