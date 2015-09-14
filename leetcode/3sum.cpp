#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
void permute(vector<int>& rem, vector<int>& done, vector<int>& ans){
	if(done.size() == 3 || rem.empty()){
		ans.push_back(done);
		return;
	}
	for(int i=0;i<rem.size();i++){
		vector<int> remaining=rem, completed=done;
		completed.push_back(remaining[i]);
		remaining.erase(remaining.begin() + i);
		permute(remaining, completed);
		permute(rem, completed);
	}
}
int main(){
	return 0;
}
