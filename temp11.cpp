#include <iostream>
#include<cstdio>
using namespace std;
int a[104],n,i,j,sum,l,T;
double dp[104][10004],p[104],ans;
int main()
{
    cin>>T;
    while(T--)
    {dp[0][0]=1;
    cin>>n;
    sum=0;
    for(i=0;i<n;i++)
    {cin>>a[i];
    sum+=a[i];
    }
    for(i=0;i<n;i++)
    {cin>>p[i];
    p[i]=double(double(p[i])/double(100));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            if(j-a[i]>=0)
            dp[i+1][j]=dp[i][j-a[i]]*p[i]+dp[i][j]*(1-p[i]);
            else
            dp[i+1][j]=dp[i][j]*(1-p[i]);
            cout << dp[i+1][j] << " ";
        }
    }
    if(sum%2==1)
    l=(sum+1)/2;
    else
    l=sum/2;
    ans=0;
    for(i=l;i<=sum;i++)
    {
        ans+=dp[n][i];
    }
    printf("%0.8f\n",ans);
    for(i=0;i<=n;i++)
    for(j=0;j<=sum;j++)
    dp[i][j]=0;
    }
    return 0;
}
