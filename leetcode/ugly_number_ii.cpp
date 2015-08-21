#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#define SIEVESIZE 1000000

using namespace std;
int nthUglyNumber(int n) {
	if(n < 1)
		return 0;
	vector<int> uglies;
	uglies.push_back(1);
	int idx2 = 0, idx3 = 0, idx5 = 0;
	for(int i=0;i<n;++i){
		int temp2 = uglies[idx2] * 2, temp3 = uglies[idx3] * 3, temp5 = uglies[idx5] * 5,min = 1000000009  ;
		min = ( temp2 > temp3 ) ? temp3 : temp2;
		min = ( min > temp5 ) ? temp5 : min;
		uglies.push_back(min);
		idx2 += (min == temp2);
		idx3 += (min == temp3);
		idx5 += (min == temp5);
	}
	return uglies[n-1];	
}

int main(){
	cout << nthUglyNumber(11) << endl;
	return 0;
}

