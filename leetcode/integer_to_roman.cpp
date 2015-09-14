#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

long long ipow(int base, int power){
	long long ans = 1;
 	while( power != 0){	
		if( power & 1 == 1)
			ans *= base;
		base *= base; 
		power >>= 1;
	}
	return ans;
}
string intToRoman(int num){
	int digits = 0, temp = num;
	string ans="";
	int values[7] = {1,5,10,50,100,500,1000};
	string symbols[7] = {"I", "V", "X", "L", "C", "D", "M"};
	int i=6;
	while(i >= 0){
		int temp = num/values[i];
		if(temp == 4){
			ans += "I";
			ans += symbols[i];
		}else if(temp == 9){

		}else{
			for(int j=0;j<temp;j++){
				ans += symbols[i];
			}
		}
		num = num - temp*values[i]; 
		--i;
	}
	return ans;
}
int main(){
	cout << intToRoman(3999)<< endl;
	return 0;
}
