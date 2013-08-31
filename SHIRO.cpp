#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;
double dp[104][10004];

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        double ans=0.0;
        int n;
        cin >> n;
        vector<int> flags(n);
        vector<double> prob(n);

        int sum=0;
        for(int i=0;i<n;i++){
            cin >> flags[i];
            sum += flags[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<sum;j++){
                dp[i][j] = 0.0;
            }
        }
        dp[0][0] = 1.0;
        int temp;
        //cout << "1 " << endl;
        for(int i=0;i<n;i++){
            cin >> temp;
            prob[i] = (double)(temp/100.0);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                if(j-flags[i] >= 0)
                    dp[i+1][j] = dp[i][j-flags[i]]*prob[i] +dp[i][j]*(1-prob[i]);
                else
                    dp[i+1][j] = dp[i][j]*(1-prob[i]);
            }
        }

        int midpoint;
        if(sum % 2 == 1)
            midpoint = (sum+1)/2;
        else
            midpoint = sum/2;

        for(int i=midpoint;i<=sum;i++){
            ans += dp[n][i];
        }

        printf("%0.8f\n",ans);
    }
    return 0;
}
