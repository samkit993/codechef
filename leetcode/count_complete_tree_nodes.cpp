#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int countNodes(TreeNode* root) {
	if(root == NULL)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}
int main(){
	return 0;
}
