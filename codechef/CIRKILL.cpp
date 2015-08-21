#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<utility>
#define sqr(x) (x)*(x)
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?a:b)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
using namespace std;

int getD(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    return (b.first*c.second - b.second*c.first - (a.first*c.second - a.second*c.first) + a.first*b.second - a.second*b.first);
}
bool isCollinear(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    if(getD(a,b,c))
        return false;
    return true;
}

int nCr(int n,int r){
    if(n==r)
        return 1;
    if(r==1)
        return n;
    long long ans = 1;
    for(int i = n,j=1;i>n-r;i--,j++){
        ans *= i;
        ans /= j;
        //cout << ans << endl;
    }
    return ans;
}

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        s(n);
        vector<pair<int,int> > points(n);
        for(int i=0;i<n;i++){
            s(points[i].first),s(points[i].second);
        }
        int coll = 0;
        double weight = nCr(n,3);
        weight = 1.0/weight;
        weight = weight/(n-3);
        double ans = 0.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(!isCollinear(points[i],points[j],points[k])){
                        int cnt=0;
                        double prob = 0.0;

                        int deter = abs(getD(points[i],points[j],points[k]));
                        int x1y1 = sqr(points[i].first) + sqr(points[i].second);
                        int x2y2 = sqr(points[j].first) + sqr(points[j].second);
                        int x3y3 = sqr(points[k].first) + sqr(points[k].second);

                        double A = getD(make_pair(points[i].second, x1y1),make_pair(points[j].second,x2y2),make_pair(points[k].second,x3y3));
                        A = A/deter;
                        double B = getD(make_pair(x1y1,points[i].first),make_pair(x2y2,points[j].first),make_pair(x3y3,points[k].first));
                        B = B/deter;
                        double C = x1y1*(points[j].first*points[k].second - points[j].second*points[k].first);
                        C -= x2y2*(points[i].first*points[k].second - points[i].second*points[k].first);
                        C += x3y3*(points[i].first*points[j].second - points[i].second*points[j].first);
                        C = C/deter;
                        //cout << A << " " << B << " " << C << endl;

                        for(int p=0;p<n;p++){
                            if(p==i || p==j || p==k )
                                continue;
                            double value = sqr(points[p].first) + sqr(points[p].second) + (points[p].first)*A + (points[p].second)*B + C;
                            if(value <= 0.0){
                                cout <<"value " << value << "a : b : c " << A << ":" << B << ":" <<C << endl;
                                cnt++;
                            }
                        }
                        ans += (double)cnt*weight;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
