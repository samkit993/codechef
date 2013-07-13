#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int p=0;p<tCases;++p){
        int n;
        scanf("%d",&n);
        vector<int> pies(n,0);
        vector<int> racks(n,0);
        for(int i=0;i<n;++i){
            scanf("%d",&pies[i]);
        }
        for(int i=0;i<n;++i){
            scanf("%d",&racks[i]);
        }
        sort(pies.begin(),pies.end());
        sort(racks.begin(),racks.end());
        int count=0;
        for(int i=0,j=0;i<n && j<n;){
            //cout << racks[i] << " " << pies[j] << endl;
            //cout << "i = " << i << "j = " << j << "count = " << count << endl << endl;
            if(racks[i] >= pies[j]){
                ++i;
                ++j;
                ++count;
            }else{
                ++i;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
