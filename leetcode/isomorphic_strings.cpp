#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
bool isIsomorphic(string s, string t){
	map<char, vector<int> > smap, tmap; 
	map<char, int> sflag, tflag;
	if(s.size() != t.size())
		return false;
	for(int i=0;i<s.size();i++){
		smap[s[i]].push_back(i);
		tmap[t[i]].push_back(i);
		sflag[s[i]] = 0;
		tflag[t[i]] = 0;
	}
	if(smap.size() != tmap.size())
		return false;
	for(int i=0;i<s.size();i++){
		if(smap[s[i]].size() != tmap[t[i]].size())
			return false;
		if(sflag[s[i]] == 1 && tflag[t[i]] == 1)
			continue;
		sort(smap[s[i]].begin(), smap[s[i]].end());
		sort(tmap[t[i]].begin(), tmap[t[i]].end());
		for(int j=0;j<smap[s[i]].size();j++){
			if(smap[s[i]][j] != tmap[t[i]][j])
				return false;
		}
		sflag[s[i]] = 1;
		tflag[t[i]] = 1;

	}
	return true;
}
int main(){
	cout << isIsomorphic("abc", "aba");
	return 0;
}
