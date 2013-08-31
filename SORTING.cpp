
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;
int counter = 0;

void sortit(int a[],int start,int stop){
    if(stop-start<=1)
        return;
    int pivot = a[(stop-start+1)/2];
    int j=0,k=0;
    int* b;
    int* c;
    for(int i=start;i<stop;i++){
        if(a[i] < pivot){
            b[j++] = a[i];
        }else if(a[i] > pivot){
            c[k++] = a[i];
        }
        counter++;
    }
    sortit(b,0,j);
    sortit(c,0,k);

}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int t=0;t<n;t++){
        cin >> a[t];
    }
    sortit(a,0,n);
    cout << counter << endl;
    return 0;
}
