#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        //m=  number of shops
        //n = number of items
        int m,n;
        scanf("%d %d",&n,&m);
        vector<vector<long long int> > price(n, vector<long long int> (m));
        vector<vector<long long int> > disc(n, vector<long long int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%lld",&price[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%lld",&disc[i][j]);
            }
        }
        //prev_index is the index for j which was chosen previously.
        int prev_index = min_element(price[0].begin(),price[0].end()) - price[0].begin();
        long long int min_price = price[0][prev_index];
        long long int temp_disc = disc[0][prev_index];

        long long int sum = 0;
        sum += min_price;

        //index is keep track of current minimum item's index.
        int index;
        // alter is for holding cost - disc or zero..
        long long int alter;
        for(int i=1;i<n;i++){
            index = min_element(price[i].begin(),price[i].end()) - price[i].begin();
            min_price = price[i][index];
            alter = (price[i][prev_index]-temp_disc > 0) ? price[i][prev_index]-temp_disc : 0;
            if(alter < min_price ){
                //prev_index = prev_index;
                sum += alter;
                temp_disc = disc[i][prev_index];
            }else if(alter == min_price){
                if(disc[i][index] >= disc[i][prev_index]){
                    sum += min_price;
                    temp_disc = disc[i][index];
                    prev_index = index;
                }else{
                    sum += alter;
                    temp_disc = disc[i][prev_index];
                }
            } else{
                prev_index = index;
                sum += min_price;
                temp_disc = disc[i][index];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
