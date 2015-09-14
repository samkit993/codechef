#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head) {
    map<ListNode *, int> mapping;
	while(head != NULL){
		if(mapping.find(head) != mapping.end())
			return head;
		mapping[head] = 1;
		head = head->next;
	}
	return NULL;

}
int main(){
	ListNode* a = new ListNode(1);
	a->next = new ListNode(9);
	a->next->next = new ListNode(9);
	a->next->next->next = new ListNode(9);
	a->next->next->next->next = a; 
	ListNode* b = detectCycle(a);
	return 0;
}
