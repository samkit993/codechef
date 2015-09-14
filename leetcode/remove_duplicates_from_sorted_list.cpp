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

void printList(ListNode* a){
	while(a != NULL){
		cout << a->val;
		a = a->next;
	}
	cout << endl;
}
ListNode* deleteDuplicates(ListNode* head){
	if(head == NULL)
		return head;
	ListNode* origHead = head, *prev;
	int cnt = 0, val = head->val;
	while(head != NULL){
		printf("head->val:%d cnt:%d val:%d\n", head->val, cnt,val);
		if(head->val == val){
			cnt++;
		}else{
			cnt = 0;
			val = head->val;
		}
		if(cnt >= 1){
			ListNode *temp = head;
			while(temp != NULL && temp->val == val){
				printf("HERE: val:%d temp->val:%d\n", val, temp->val);
				temp = temp->next;
			}
			printf("Before val:%d head->val:%d temp->val:%d \n", val,head->val, temp->val);
			if(head != temp){
				if(temp == NULL){
					prev->next = NULL;
				}else{
					prev->next = temp;
				}
				head = prev->next;
				//printf("After val:%d head->val:%d temp->val:%d \n", val,head->val, temp->val);
			}else{
				prev = head;
				head = head->next;
			}
		}else{
			prev = head;
			if(head != NULL)
				head = head->next;
		}
	}
	return origHead;
}
int main(){
	ListNode* a = NULL;
	a = new ListNode(1);
	a->next = new ListNode(1);
	a->next->next = new ListNode(2);
	a->next->next->next = new ListNode(3);
	a->next->next->next->next = new ListNode(3);
	ListNode *ans = deleteDuplicates(a); 
	printList(ans);
}
