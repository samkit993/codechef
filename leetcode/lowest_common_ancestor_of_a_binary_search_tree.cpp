#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(p->val == root->val || q->val == root->val)
		return root;
	if(p->val > root->val && r->val > root->val){
		lowestCommonAncestor(root->right, p,q);
	}else if(p->val < root->val && q->val < root->val){
		lowestCommonAncestor(root->left, p,q);
	}else{
		return root;
	}
}
int main(){
	return 0;
}
