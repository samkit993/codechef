#include<cstdio>
#include<iostream>
using namespace std;

void multiplication(int* arr,int n, int& m){
    //cout << "value of n and m are " << n  << " and " << m << endl;
    int temp=0;
    for(int i=m;i>0;--i){
        int temp2 = arr[m-i]*n + temp;
        arr[m-i] = temp2%10;
        temp = temp2/10;
        //cout << m-i << " " << arr[m-i]<< endl;
    }

    while(temp > 0 ){
        arr[m] = temp%10;
        temp = temp/10;
        //cout << m << " " << arr[m] << endl;
        ++m;
    }

}

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int p=0;p<tCases;p++){
        int num;
        int arr[200];
        int m = 1;
        arr[0] = 1;

        scanf("%d",&num);
        for(int q=num;q>1;--q){
            multiplication(arr,q,m);
        }
        for(int i=m-1;i>=0;--i){
            cout << arr[i];
        }
        cout << endl;
    }
    return 0;
}
