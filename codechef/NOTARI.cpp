#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) (x)*(x)
using namespace std;

/*********************************
 *This solution will work only   *
 *for n<=30                      *
 *********************************/
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
    while(true){
        int n,ans;
        scanf("%d",&n);
        if(n==0)
            break;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        //cout << "complete" << endl;
        int j,c;
        ans = 0;
        for(int i=0;i<(1 << n);i++){
            vector<int> temp;
            for(j=0,c=0;j<32;j++)
                if(i & (1 << j))
                    c++;
            //cout << c << endl;
            if(c==3){
                for(j=0;j<32;j++)
                    if(i & (1 << j))
                        temp.push_back(arr[j]);
                int max = *max_element(temp.begin(),temp.end());
                int sum = 0;
                for(int p=0;p<3;p++){
                    if(temp[p]!= max)
                        sum += temp[p];

                }
                //cout << sum << " " << max << endl;
                if(sum < max)
                    ans+=1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
