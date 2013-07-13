#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int findMin(int a,int b,int c){
    if(a<b && a<c){
        return a;
    }else if(b<a && b < c){
        return b;
    }else{
        return c;
    }
}
int main(){
    int n1,n2,n3;
    int i,j,k;
    vector<int> list;
    scanf("%d %d %d",&n1,&n2,&n3);

    vector<int> l1(n1),l2(n2),l3(n3);
    for(i=0;i<n1;++i){
        scanf("%d",&l1[i]);
    }
    for(j=0;j<n2;++j){
        scanf("%d",&l2[j]);
    }
    for(k=0;k<n3;++k){
        scanf("%d",&l3[k]);
    }
    sort(l1.begin(),l1.end());
    sort(l2.begin(),l2.end());
    sort(l3.begin(),l3.end());
    i=0;
    j=0;
    k=0;
    for(int p=0;(i<n1 || j<n2) && (j<n2 || k<n3) && (i < n1 || k < n3);++p){
        if(l1[i] == l2[j]){
            list.push_back(l1[i]);
            if(l1[i] == l3[k])
                ++k;
            ++i;
            ++j;
        }else if(l2[j] == l3[k]){
            list.push_back(l2[j]);
            if(l1[i] == l2[j])
                ++i;
            ++j;
            ++k;
        }else if(l1[i] == l3[k]){
            list.push_back(l3[k]);
            if(l2[j] == l3[k])
                ++j;
            ++i;
            ++k;
        }else{
            if(l1[i] < l2[j] && l1[i] < l3[k]){
                while(l1[i] < l2[j] || l1[i] < l2[k] ){
                    ++i;
                }
            }else if(l2[j] < l3[k] && l2[j] < l1[i]){
                while(l2[j] < l3[k] || l2[j] < l1[i]){
                    ++j;
                }
            }else{
                while(l3[k] < l1[i] && l3[k] < l2[j]){
                    ++k;
                }
            }

        }
    }
    printf("%d\n",list.size());
    for(i=0;i<list.size();++i){
        printf("%d",list[i]);
        if(i!=list.size()-1)
            printf("\n");
    }
    return 0;
}
