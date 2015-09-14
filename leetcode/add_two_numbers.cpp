#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int ipow(int base, int p){
	int ans = 1;
	while(p != 0){
		if(p & 1)
			ans *= base;
		base *= base;
		p >>= 1;
	}
	return ans;
}
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
int listToInt(ListNode *a){
	int ans = 0, cnt = 0;
	while(a != NULL){
		ans += ipow(10, cnt)*a->val;
		a = a->next;
		++cnt;
	}
	return ans;
}
ListNode* intToList(int a){
	ListNode* ans = new ListNode(a%10), *temp = NULL;
	a /= 10;
	temp = ans;
	while(a > 0){
		temp->next = new ListNode(a%10);
		a /= 10;
		temp = temp->next;
	}
	return ans;
}
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
	int i1 = listToInt(l1), i2 = listToInt(l2);
	cout << "Converted numbers: " << i1 << " " << i2 << endl;
	int ans = i1 + i2;
	return intToList(ans);
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *r1 = l1, *r2 = l2;
	int carry = 0, cnt = 0;
	ListNode *temp = NULL, *ans = NULL;
	temp = new ListNode((carry + r1->val + r2->val)%10);
	carry = (carry + r1->val + r2->val)/10;
	ans = temp;
	r1 = r1->next;
	r2 = r2->next;
	int v1, v2;
	v1 = (r1 == NULL) ? 0 : r1->val;
	v2 = (r2 == NULL) ? 0 : r2->val;
	while(r1 != NULL || r2 != NULL){
		//printf("r1->val:%d, r2->val:%d, Digit: %d, Carry:%d, temp->val:%d, ans->next is NULL: %d\n",v1, v2,(carry + v1 + v2)%10,(carry + v1+ v2)/10, temp->val, ans->next == NULL);
		temp->next = new ListNode((carry + v1 + v2)%10);
		carry = (carry + v1 + v2)/10;
		r1 = (r1 == NULL) ? r1 : r1->next;
		r2 = (r2 == NULL) ? r2 : r2->next;
		v1 = (r1 == NULL) ? 0 : r1->val;
		v2 = (r2 == NULL) ? 0 : r2->val;
		cnt++;
		temp = temp->next;
	}
	if(carry > 0){
		temp->next = new ListNode(carry);
		temp = temp->next;
	}
	return ans;
}

int main(){
	ListNode* a = new ListNode(1);
	a->next = new ListNode(9);
	a->next->next = new ListNode(9);
	a->next->next->next = new ListNode(9);
	a->next->next->next->next = new ListNode(9);
	a->next->next->next->next->next = new ListNode(9);
	a->next->next->next->next->next->next = new ListNode(9);
	a->next->next->next->next->next->next->next = new ListNode(9);
	a->next->next->next->next->next->next->next->next = new ListNode(9);
	a->next->next->next->next->next->next->next->next->next = new ListNode(9);
	ListNode* b = new ListNode(9);
	printList(addTwoNumbers(a,b));
	return 0;
}
