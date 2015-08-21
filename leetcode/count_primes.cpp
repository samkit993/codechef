#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int countPrimes(int n) {
	vector<bool> sieve(n,true);
	int sqroot = sqrt(n);
	sieve[0] = false;
	sieve[1] = false;
	for(int i=2;i<=sqroot;++i){
		if(sieve[i]){
			int temp = 2*i;
			while(temp < sieve.size()){
				sieve[temp] = false;
				temp += i;
			}
		}
	}
	return count(sieve.begin(), sieve.end(), true);
}
int main(){
	cout << countPrimes(5);
	return 0;
}
