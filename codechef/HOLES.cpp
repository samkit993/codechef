#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[26] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
int main(){
    int tCases;
    scanf("%d",&tCases);
    cin.ignore();
    for(int i =0;i<tCases;i++){
        string temp;
        int holes=0;
        getline(cin,temp);
        for(int j=0;j<temp.size();j++){
            holes += arr[temp[j]-'A'];
        }
        cout << holes << endl;
    }
    return 0;
}
