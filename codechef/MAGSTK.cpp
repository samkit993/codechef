#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int tCases;

    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        int n;
        scanf("%d",&n);
        map<int,int> sticks;
        map<int,int>::iterator it,it1;
        int temp,temp1;
        vector<int> original(n);
        for(int i=0;i<n;i++){
            cin >> temp >> temp1;
            sticks[temp] = temp1;
            original[i] = temp;
        }

        //sort(sticks.begin(),sticks.end());
        vector<int> answers(n);
        int i=0,range;
        for(it=sticks.begin();it!=sticks.end();it++,i++){
            it1 = ++it;
            it--;
            temp = 1;
            range = it->first + it->second;
            for(;it1!=sticks.end();it1++){
                if(range > it1->first ){
                    range += it->second;
                    temp++;
                }else{
                    break;
                }
            }
            answers[i] = temp;
        }
        i=0;
        for(map<int,int>::iterator it=sticks.begin();it!=sticks.end();it++,i++){
            it->second = answers[i];
        }
        cout << endl;
        for(i=0;i<n;i++){
            cout << sticks[original[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}
