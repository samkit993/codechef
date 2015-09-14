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
	if(root == p || root == q || root == NULL)
		return root;
	TreeNode* left = lowestCommonAncestor(root->left, p,q);
	TreeNode* right = lowestCommonAncestor(root->right, p,q);
	if(left != NULL && right != NULL)
		return root;
	else if(left != NULL && right == NULL)
		return left;
	else if(left == NULL && right != NULL)
		return right;
	return NULL;
}
int main(){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->right->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	TreeNode *ans = lowestCommonAncestor(root, root->left->right->right, root->left->right->right);
	cout << ans->val << endl;
	
	return 0;
}
