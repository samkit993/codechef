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
    int count=0;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int x1,x2,x3,y1,y2,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int d1 = sqr((y2 - y1)) + sqr((x2 - x1));
        int d2 = sqr((y3 - y1)) + sqr((x3 - x1));
        int d3 = sqr((y3 - y2)) + sqr((x3 - x2));
        if(d1 > d2 && d1 > d3){
            if(d1 == d2 + d3)
                count++;
        }else if(d2 > d3 && d2 > d1){
            if(d2 == d1 + d3)
                count++;
        }else{
            if(d3 == d1+d2)
                count++;
        }
    }
    cout << count << endl;
    return 0;
}
