#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
bool compNode(ListNode* a, ListNode* b){
	return a->val > b->val;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(), first = 1;;
		vector<ListNode*> heap;
		for(int i=0;i<n;i++){
			if(lists[i]) {
				heap.push_back(lists[i]);
			}
		}
		make_heap(heap.begin(), heap.end(), compNode);
		ListNode *head = NULL, *start = NULL;
		start = head;
		while(heap.size()){
			if(first){
				head = heap.front(); 
				start = head;
				first = false;
				//printf("Setting head next to %d  Is next NULL: %d\n", head->val, head->next == NULL);
			}else{
				head->next = heap.front();
				head = head->next;
				//printf("Setting head next to %d  Is next NULL: %d\n", head->val, head->next == NULL);
			}
			pop_heap(heap.begin(), heap.end(), compNode);
			heap.pop_back();
			if(head->next){
				heap.push_back(head->next);
				push_heap(heap.begin(), heap.end(), compNode);
			}
		}
		return start;
}

int main(){
	vector<ListNode*> heads;
	ListNode* h1 = new ListNode(10);
	h1->next = new ListNode(15);
	heads.push_back(h1);

	ListNode* h2 = new ListNode(11);
	h2->next = new ListNode(16);
	heads.push_back(h2);
	
	ListNode* h3 = new ListNode(9);
	h3->next = new ListNode(26);
	heads.push_back(h3);

	ListNode *ans = mergeKLists(heads);
	while(ans->next != NULL){
		printf("%d\n", ans->val);
		ans = ans->next;
	}
	printf("%d\n", ans->val);
	return 0;
}
