#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

unsigned long long ipow(int base, int power){
	unsigned long long ans = 1;
 	while( power != 0){	
		if( power & 1 == 1)
			ans *= base;
		base *= base; 
		power >>= 1;
	}
	return ans;
}

long long stoi(string str){
	bool minus = false;
	if(str[0] == '-'){
		minus = true;
		str = str.substr(1,str.size());
	}
	unsigned long long ans = 0; 
	int n = str.size();
	for(int i=n-1;i>=0;--i){
		ans += ((int)(str[i] - '0'))*ipow(10, n-1-i);
	}
	return minus ? -ans : ans;
}
 int calculate(string s) {
	 int ans;
	string temp = "";
	char op;
	vector<int> nums;
	vector<char> ops;
	for(int i=0;i<s.size();i++){
		if(s[i] == ' ')
			continue;
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			ops.push_back(s[i]);
			i++;
			nums.push_back(stoi(temp));
			temp = "";
		}
		temp += s[i];
	}
	
	printf("Num1:%d, op:%c, Num2:%d\n",num1, op, num2);
	switch(op){
		case '+':
			ans = num1 + num2;
			break;
		case '*':
			ans = num1*num2;
			break;
		case '-':
			ans = num1-num2;
			break;
		case '/':
			if(num2 == 0)
				return -1;
			ans = num1/num2;
			break;
		default:
			ans = -1;
			break;
	}
	return ans;
 }
int main(){
	cout << calculate("1+2") << endl; 
	cout << calculate("3+2*2") << endl; 
	cout << calculate(" 3/2 ") << endl; 
	cout << calculate(" 3+5 / 2 ") << endl; 
	return 0;
}
