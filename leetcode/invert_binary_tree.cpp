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

TreeNode* invertTree_helper(TreeNode* root){
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return root;
	TreeNode *temp=root->left;
	root->left = root->right;
	root->right = temp;
	invertTree_helper(root->left);
	invertTree_helper(root->right);
	return root;
}
TreeNode* invertTree(TreeNode* root) {
	TreeNode* orig_root = root;
	invertTree_helper(root);
}
int main(){
	return 0;
}
