#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<functional>
#define sqr(x) (x)*(x)
using namespace std;

void show(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout << a[i];
    }
    cout << endl;
}

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        //n = number of rooms
        //m = choices made by elephant
        //choices = array which contains sequence in which elephant visits each room
        //bRooms = contains number of bottles in each room
        //bottles = 2-dimensional vector which contain volume of
        //          jth bottle out of total bRooms[i] bottle of ith rooms
        int n,m;
        cin >> n >> m;
        vector<int> choices(m);
        vector<vector<int> > bottles(n,vector<int>(1));
        for(int i=0;i<m;i++){
            cin >> choices[i];
        }
        sort(choices.begin(),choices.end());
        vector<int> bRooms(n);
        for(int i=0;i<n;i++){
            cin >> bRooms[i];
            bottles[i].resize(bRooms[i]);
            for(int j=0;j<bRooms[i];j++){
                cin >> bottles[i][j];
            }
            sort(bottles[i].begin(),bottles[i].end(),greater<int>());
        }
        long int total = 0;
        for(int i=0;i<m;i++){
            int j = 0;
            //cout << choices[i] << " " << j << " " << bottles[choices[i]].size() << " "<< bottles[choices[i]][j] << endl;
            total += bottles[choices[i]][j];
            while(choices[i] == choices[i+1]){
                i++,j++;
                if(j < bottles[choices[i]].size())
                    total += bottles[choices[i]][j];
                //cout << choices[i] << " " << j << " " << bottles[choices[i]].size() << " " << bottles[choices[i]][j] << " " << total << endl;
            }
        }
        cout << total << endl;
    }
    return 0;
}
