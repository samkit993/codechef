#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<utility>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int tCases;
    scanf("%d",&tCases);
    vector<pair<int,int> > space;
    vector<pair<int,int> >::iterator it;
    pair<int, int> temp;
    for(int t=0;t<tCases;t++){
        string str;
        int a,b;
        cin >> str >> a >> b;
        temp = make_pair(a,b);

        if(str == "add"){
            if(find(space.begin(),space.end(),temp)==space.end()){
                space.push_back(temp);
            }
        }else if(str == "erase"){
            it = find(space.begin(),space.end(),temp);
            space.erase(it);
        }else if(str == "get"){
            sort(space.begin(),space.end());
            for(it=space.begin();it!=space.end();it++){
                //cout << it->first << " " << it->second << endl;
                if(it->first >= temp.first)
                    break;
            }
            it--;
            cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}
