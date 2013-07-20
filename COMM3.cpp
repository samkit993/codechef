#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define sqr(x) (x)*(x)
using namespace std;
struct point{
    int x;
    int y;
};

bool isPossible(point* a,int range){
    float d[3];
    d[0] = sqrt(sqr(a[1].y-a[0].y)+sqr(a[1].x-a[0].x));
    d[1] = sqrt(sqr(a[2].y-a[1].y)+sqr(a[2].x-a[1].x));
    d[2] = sqrt(sqr(a[0].y-a[2].y)+sqr(a[0].x-a[2].x));
    int count=0;
    for(int i=0;i<3;i++){
        if(d[i]<=range)
            count++;
    }
    if(count>=2)
        return true;
    return false;
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int r;
        scanf("%d",&r);
        float d[3];
        point chef[3];
        for(int i=0;i<3;i++){
            scanf("%d %d",&chef[i].x,&chef[i].y);
        }
        if(isPossible(chef,r))
            printf("yes\n");
        else
            printf("no\n");

    }
    return 0;
}
