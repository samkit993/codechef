#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr.begin(),arr.end());
        int max=1,index=0;
        int value,count;
        for(int i=0;i<n;){
            value = arr[i];
            count = 1;
            while(arr[++i] == value)
                ++count;
            if(count >= max){
                if(count == max){
                    if(arr[i-1] < arr[index]){
                        max = count;
                        index = i-1;
                    }
                } else {
                    max = count;
                    index = i-1;
                }
            }
        }
        printf("%d %d\n",arr[index],max);
    }
    return 0;
}
