#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int tCases;
    cin >> tCases;
    for(int t=0;t<tCases;t++){
        float d;
        int usage;
        int n;
        cin >> d >> usage >> n;
        int validity[n];
        float rate[n];
        int cost[n];
        float profit[n];
        float previous = usage*d;
        //float previous = ((int)(usage*d*100))/100.0;
        int ans;
        float temp = 0.0;
        for(int i=0;i<n;i++){
            cin >> validity[i] >> rate[i] >> cost[i];
            profit[i] = previous - (cost[i]/(float)validity[i]) - (rate[i]*usage);
            profit[i] = ((profit[i] < 0) ? 0 : profit[i]);
            if(profit[i] > temp){
                temp = profit[i];
                ans = i+1;
            }
        }
        if(temp == 0.0)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
