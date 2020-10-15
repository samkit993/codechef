#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int wd;
    float bal;
    scanf("%d %f",&wd,&bal);
    if(wd % 5 == 0 && bal-(wd + 0.50) > 0){
        bal -= (wd + 0.50);
    }
    printf("%.2f",bal);
    return 0;
}
