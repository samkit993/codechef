#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n,q;
        cin >> n >> q;
        int a[n];
        int cnt[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            cnt[i] = 0;
        }
        sort(a,a+n);
        int aa,bb;
        for(int i=0;i<q;i++){
            cin >> aa >> bb;
            --aa,--bb;
            for(int j=aa;j<=bb;j++){
                cnt[j]++;
            }
        }
        long long sum = 0;
        sort(cnt,cnt+n);
        for(int i=0;i<n;i++){
            if(cnt[i]){
                sum += cnt[i]*a[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
