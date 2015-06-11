#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


/**
 * Definition for binary tree
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
	TreeNode *first, *second;
    TreeNode *prev;       
public:
    void recoverTree(TreeNode *root) {
    	if(!root)
    		return;
		first = second = NULL;
		prev = new TreeNode(INT_MIN);
		inorder(root);
		if(first and second) {
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
    }

	void inorder(TreeNode *root)
	{
		if(!root)
			return;
		inorder(root->left);
		if(!first and prev->val >= root->val)
			first = prev;
		if(first and prev->val >= root->val)
			second = root;
		prev = root;
		inorder(root->right);
	}
};

void printTree(TreeNode *temp)
{
	if(!temp)
		return;
	printTree(temp->left);
	cout<<temp->val;
	printTree(temp->right);
}

int main()
{
	Solution sol;
	TreeNode *root;
	root = new TreeNode(4);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(6);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(2);
	printTree(root);
	sol.recoverTree(root);cout<<endl;
	printTree(root);
	return 0;
}
