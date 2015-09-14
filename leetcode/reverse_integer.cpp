#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
using namespace std;

int ipow(int b,int p){
	int ans = 1;
	while(p > 0){
		if(p & 1 == 1)
			ans *= b;
		b *= b;
		p >>= 1;
	}
	return ans;
}
int reverse(int x){
	bool minus = false;
	if( x < 0){
		x = -x;
		minus = true;
	}
	long long int y=0;
	vector<int> digits;
	while(x > 0){
		digits.push_back(x%10);
		x = x/10;
	}
	
	for(int i=digits.size()-1;i>=0;--i){
		y += (long long)ipow(10, digits.size()-i-1)*digits[i];
	}
	y = (minus) ? -y : y;
	y = (y > INT_MAX) ? 0 : y;
	y = (y < INT_MIN) ? 0 : y;
	return y;
}
int main(){
	cout << reverse(1463847412);
	return 0;
}
