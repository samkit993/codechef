#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

struct point{
    int x, y;
};

int maxi(int a,int b,int c,int &sum){
    if(a >= b && a >= c){
        sum = b + c;
        return a;
    }else if(b >= a && b >= c){
        sum = a + c;
        return b;
    }else{
        sum = a + b;
        return c;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    point points[n];
    int sides = n*(n-1)/2;
    vector<int> d(sides);
    for(int t=0;t<n;t++){
        cin >> points[t].x >> points[t].y;
    }
    int temp,sum,ans=0,k=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            temp = sqr(points[i].x-points[j].x) + sqr(points[i].y-points[j].y);
            //cout << d1 << " " << d2 << " " << d3 << " " << sum << " "<< temp << endl;
            d[k++] = temp;
        }
    }
    sort(d.begin(),d.end());
    cout << ans << endl;
    /*sort(d.begin(),d.end());
    int temp,sum;
    int ans = 0;
    //vector<float>::iterator it;
    for(int i=0;i<sides;i++){
        for(int j=i+1;j<sides;j++){
            for(int k=j+1;k<sides;k++){
                temp = maxi(d[i],d[j],d[k],sum);
                cout << d[i] << " " << d[j] << " " << d[k] << " " << sum  << " " << temp << endl;
                if(sum > temp){
                    ans++;
                }
            }
        }
    }
    cout << ans;*/

    return 0;
}
