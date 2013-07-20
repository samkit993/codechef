#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        vector<int> leaves(n);
        int stems;
        for(int i=0;i<leaves.size();i++){
            scanf("%d",&leaves[i]);
        }
        bool valid = true;
        stems = 1;
        for(int i=0;i<leaves.size();i++){
            if(stems>1000000){
                valid=false;
                break;
            }
            stems -= leaves[i];
            stems = 2*stems;
            if((i!=n-1 && stems<=0) || (i==n-1 && stems!=0)){
                valid = false;
                break;
            }
        }
        if(valid)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
