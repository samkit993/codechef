#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<vector<int> > cycle_list;
    vector<int> tempV;
    int cycles = 0;

    scanf("%d",&n);
    int arr[n+1];
    bool checked[n+1];
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
        checked[i]=false;
    }
    int next = 1;
    int first = arr[next];
    //checked[next] = true;
    //tempV.push_back(arr[next]);
    while(true){
        bool complete = true;
        int temp = arr[next];
        checked[next] = true;
        tempV.push_back(next);
        next = arr[temp];
        if(next == first){
            tempV.push_back(temp);
            checked[temp]= true;
            ++cycles;
            cycle_list.push_back(tempV);
            tempV.clear();
            for(int i=1;i<=n;++i){
                if(checked[i]==false){
                    complete = false;
                    next = i;
                    first = arr[next];
                    break;
                }
            }
        }else {
            next = temp;
            complete = false;
        }
        if(complete)
            break;
    }
    printf("%d\n",cycles);
    for(int i=0;i<cycle_list.size();++i){
        for(int j=0;j<cycle_list[i].size();++j){
            printf("%d",cycle_list[i][j]);
            if(j!=cycle_list[i].size()-1)
                printf(" ");
        }
        printf("\n");
    }
}

