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

string itos(long long a){
	bool negative = ( a >= 0 ) ? false : true;
	if(negative)
		a = -a;
	string str;	
	while(a > 0){
		str += (char( '0' + a % 10));
		a /= 10;
	}
	reverse(str.begin(), str.end());
	if(negative)
		str = '-' + str;
	return str;
}
void buildPath(TreeNode* root,string now, vector<string> &ans){
	if(root == NULL){
		return;
	}
	if(now == ""){
		now += itos(root->val);
	}else{
		now += "->" + itos(root->val);
	}
	if(root->left == NULL && root->right == NULL){
		ans.push_back(now);
	}else if(root->left == NULL){
		buildPath(root->right, now, ans);
	}else if(root->right == NULL){
		buildPath(root->left, now, ans);
	}else{
		buildPath(root->left, now, ans);
		buildPath(root->right, now, ans);
	}
	return;
}
vector<string> binaryTreePaths(TreeNode* root){
	vector<string> ans;
	buildPath(root, "", ans);
	return ans;
}
int main(){

	vector<string> ans = binaryTreePaths(NULL);
	cout << "Binary Paths printing start now " << endl;
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << endl;
	}
	TreeNode *tree = new TreeNode(1);
	ans = binaryTreePaths(tree);
	cout << "Binary Paths printing start now " << endl;
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << endl;
	}
	tree->left = new TreeNode(-2);
	tree->right = new TreeNode(3);
	ans = binaryTreePaths(tree);
	cout << "Binary Paths printing start now " << endl;
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << endl;
	}

	tree->left->left = new TreeNode(4);
	tree->right->right = new TreeNode(5);

	ans = binaryTreePaths(tree);
	cout << "Binary Paths printing start now " << endl;
	for(int i=0;i<ans.size();++i){
		cout << ans[i] << endl;
	}
	return 0;
}
