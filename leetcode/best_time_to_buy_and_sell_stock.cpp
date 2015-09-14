#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
	return *max_element(prices.begin(), prices.end()) - *max_element(prices.begin(), prices.end())
}
int main(){
	return 0;
}
