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
void printList(ListNode* a){
	while(a != NULL){
		cout << a->val;
		a = a->next;
	}
	cout << endl;
}
ListNode* revList(ListNode *a){
	if(a == NULL || a->next == NULL){
		return a;
	}
	ListNode *ans = NULL,*second = a->next, *third = a->next->next;
	second->next = a;
	a->next = NULL;
	if(third == NULL)
		return second;
	ListNode *currNode = third, *prevList = second;
	while(currNode != NULL){
		ListNode *nextNode = currNode->next;
		currNode->next = prevList;
		prevList = currNode;
		currNode = nextNode;
	}
	return prevList;
}
bool isPalindrome(ListNode* head){
	vector<int> list,revlist;
	while(head->next != NULL){
		list.push_back(head->val);
		revlist.push_back(head->val);
		head = head->next;
	}
	reverse(revlist.begin(), revlist.end());
	return list == revlist;
}
int main(){
	ListNode* a = new ListNode(1);
	a->next = new ListNode(1);
	a->next->next = new ListNode(2);
	a->next->next->next = new ListNode(1);
	cout << isPalindrome(a);
	return 0;
}
