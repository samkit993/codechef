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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if(head->next == NULL)
		return NULL;
	ListNode* ret = head;
	int cnt = 1;
	while(head->next != NULL){
		head = head->next;
		cnt += 1;
	}
	head = ret;
	cnt = cnt - n;
	ListNode *curr;
	cout << cnt << endl;
	while(cnt != 0){
		curr = head;
		head = head->next;
		cnt--;
	}
	if(head->next == NULL){
		curr->next = NULL;
	}else if(head == ret){
		ret = head->next;
	}else{
		head->val = head->next->val;
		head->next= head->next->next;
	}
	//delete(head);
	return ret;
}
void printList(ListNode *head){
	if(head == NULL)
		return;
	while(head->next != NULL){
		printf("%d ", head->val);
		head = head->next;
	}
	printf("%d\n", head->val);
}
int main(){
	ListNode* h1 = new ListNode(10);
	h1->next = new ListNode(15);
	h1->next->next = new ListNode(5);
	ListNode *ans = removeNthFromEnd(h1,2);
	//printList(h1);
	printList(ans);
	return 0;
}
