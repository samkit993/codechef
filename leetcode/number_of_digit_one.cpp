#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
long long ipow(int base, int power){
	if(power < 0)
		return 0;
	long long ans = 1;
	while(power > 0){
		if( power & 1 ){
			ans *= base;
		}
		base *= base;
		power >>= 1;
	}
	return ans;
}
int countDigitOne(int n) {
	int pow10 = log10(n);	
	vector<int> ones(pow10);
	for(int i=1;i<=pow10;i++){
		ones[i] = i*ipow(10, i-1) + 1;
	}
	int tempn = n, tpow10 = pow10,ans = 0;
	while(tempn > 0){
		ans += ones[tpow10];
		tempn -= ipow(10, tpow10);
		int low = ipow(10, tpow10) + ipow(10, tpow10-1), high = ipow(10, tpow10) + 2*ipow(10, tpow10-1);
		printf("tempn:%d low:%d high:%d\n", tempn, low, high);
		if(tempn > low && tempn <= high ){
			printf("n:%d pow10:%d tempn:%d tpow10:%d ans:%d \n",n,pow10, tempn,tpow10, ans);
			if(n >= high)
				ans += ipow(10, tpow10);
			else
				ans += (n - low);
			printf("n:%d pow10:%d tempn:%d tpow10:%d ans:%d \n",n,pow10, tempn,tpow10, ans);
		}
		if(tempn < ipow(10, tpow10))
			--tpow10;
	}
	return ans;
}

int main(){
	cout << countDigitOne(101) << endl;
	cout << countDigitOne(23) << endl;
	return 0;
}
