#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n1,n2,n3;
    scanf("%d %d %d",&n1,&n2,&n3);
    vector<int> arr;
    vector<int> ans;
    int temp;
    for(int i=0;i<n1+n2+n3;i++){
        scanf("%d",&temp);
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    //for(int i=0;i<arr.size();++i)
        //cout << arr[i] << endl;
    int value;
    int count;
    for(int i=0;i<arr.size();){
        value = arr[i];
        count = 1;
        while(arr[++i]==value){
            count++;
        }
        //cout << count << endl;
        if(count >= 2)
            ans.push_back(value);
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
}
