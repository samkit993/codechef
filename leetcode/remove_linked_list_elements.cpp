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
ListNode* removeElements(ListNode* head, int val){
	if(head == NULL)
		return head;
	while(head->val == val){
		head = head->next;
		if(head == NULL)
			break;
	}
	ListNode* origHead = head;
	if(head == NULL || head->next == NULL)
		return head;

	while(head->next != NULL){
		if(head->next->val == val){
			head->next = head->next->next;
		}else{
			head = head->next;
		}
		if(head == NULL)
			break;
	}
	return origHead;
}

void printList(ListNode* a){
	while(a != NULL){
		cout << a->val;
		a = a->next;
	}
	cout << endl;
}
int main(){
	ListNode* a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(2);
	a->next->next->next = new ListNode(1);
	printList(a);
	ListNode* ans = removeElements(a, 2);
	printList(ans);
	return 0;
}
