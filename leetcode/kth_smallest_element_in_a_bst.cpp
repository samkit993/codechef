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

void wrapper(TreeNode* root, vector<int> &arr){
	if(root == NULL)
		return;
	arr.push_back(root->val);
	wrapper(root->left, arr);
	wrapper(root->right, arr);
}
int kthSmallest(TreeNode* root, int k){
	vector<int> inorder;
	wrapper(root, inorder);	
	for(int i=0;i<inorder.size();++i){
		printf("%d\n", inorder[i]);
	}
	sort(inorder.begin(), inorder.end());
	return inorder[k-1]; 
}


int main(){
	TreeNode *root = new TreeNode(3);
	cout << kthSmallest(root, 1);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->right->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	return 0;
}
