#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int tCases;
    cin >> tCases;
    cin.ignore();
    while(tCases > 0){
        long int num,nFives = 0;
        cin >> num;
        cin.ignore();
        for(long int i=5;i<=num;i*=5){
            nFives += int(num/i);
        }
        printf("%d\n",nFives);
        --tCases;
    }
    return 0;
}
