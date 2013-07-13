#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>

using namespace std;

bool subsum(int arr[],int n, int sum){
    if(sum == 0){
        return true;
    }
    if(n == 0 && sum!=0){
        return false;
    }
    if(arr[n-1] > sum)
        return subsum(arr,n-1,sum);


    return subsum(arr,n-1,sum-arr[n-1]) || subsum(arr, n-1, sum);
}
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int p=0;p<tCases;++p){
        int nNotes, sum;
        scanf("%d %d",&nNotes, &sum);
        int arr[nNotes];
        for(int i=0; i<nNotes; ++i){
            scanf("%d",&arr[i]);
        }
        cout << (subsum(arr,nNotes,sum) ? "Yes" : "No") << endl;
    }

    return 0;
}
