#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int p=0;p<tCases;p++){
        int size;
        scanf("%d",&size);
        vector<vector<int> > arr(size,vector<int>(size,0));
        vector<vector<int> > sum(size,vector<int>(size,0));

        for(int i=0;i<size;++i){
            for(int j=0;j<=i;++j){
                scanf("%d",&arr[i][j]);
            }
        }
        sum[0][0] = arr[0][0];
        int ans = 0;
        for(int i=1;i<size;++i){
            for(int j=0;j<=i;++j){
                if(j==0){
                    sum[i][j] = arr[i][j] + sum[i-1][j];
                }else if(i==j){
                    sum[i][j] = arr[i][j] + sum[i-1][j-1];
                }else{
                    sum[i][j] = arr[i][j] + max(sum[i-1][j],sum[i-1][j-1]);
                }

                if(sum[i][j] > ans)
                    ans = sum[i][j];
            }
        }
        if(sum[0][0] > ans)
            ans = sum[0][0];
        printf("%d\n",ans);
    }
    return 0;
}
