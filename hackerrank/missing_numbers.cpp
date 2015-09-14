#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
	int n,m;
	scanf("%d",&n);
	map<int,int> listA,listB;
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		if(listA.find(temp) == listA.end()){
			listA[temp] = 1;
		}else{
			listA[temp]++;
		}
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int temp;
		scanf("%d",&temp);
		if(listB.find(temp) == listB.end()){
			listB[temp] = 1;
		}else{
			listB[temp]++;
		}
	}
	
	map<int,int>::iterator it1=listA.begin(), it2=listB.begin();
	while(it1 != listA.end() && it2 != listB.end()){
		if(it1->first == it2->first){
			if(it1->second != it2->second)
				printf("%d ", it1->first);
			it1++;
			it2++;
		}else if(it1->first < it2->first){
			printf("%d ", it1->first);
			it1++;
		}else if(it1->first > it2->first){
			printf("%d ", it2->first);
			it2++;
		}
	}
	if(it1 != listA.end()){
		while(it1 != listA.end()){
			printf("%d ", it1->first);
			++it1;
		}
	}
	if(it2 != listB.end()){
		while(it2 != listB.end()){
			printf("%d ", it2->first);
			++it2;
		}
	}

	return 0;
}
