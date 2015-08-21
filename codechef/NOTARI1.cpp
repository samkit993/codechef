#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;

/*********************************
 *This solution will work only   *
 *n > 30 also                    *
 *********************************/

int main(){
    while(true){
        int n,ans=0;
        scanf("%d",&n);
        if(n==0)
            break;

        vector<int> arr(n);
        for(int p=0;p<n;p++)
            scanf("%d",&arr[p]);
        int sum=0;
        sort(arr.begin(),arr.end());
        int i,j,k;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1;k<n;k++){
                    //cout << k << endl;
                    if(arr[k] > (arr[i] + arr[j]))
                        break;
                }
                //cout << k << endl;
                ans += (n-k);
                //sum = arr[i] + arr[j];
                //vector<int>::iterator h = upper_bound(arr.begin(),arr.end(),sum);
                //ans += n-(h-arr.begin());
            }
        }
        cout << ans << endl;
    }
    return 0;
}
