
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> seq(n);
    vector<int> left(q);
    vector<int> right(q);
    vector<int> k(q);
    for(int i=0;i<n;i++){
        cin >> seq[i];
    }
    for(int i=0;i<q;i++){
        cin >> left[i] >> right[i] >> k[i];
        int count=0;
        for(int j =left[i]-1;j<=right[i]-1;j++){
            if(seq[j]%k[i]==0)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
