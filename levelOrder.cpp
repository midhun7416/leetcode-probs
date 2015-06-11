#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		TreeLinkNode *curr, *head=NULL, *prev=NULL;
		curr = root;
		while(curr)
		{
			if(curr->left)
			{
				if(prev)
					prev->next=curr->left;
				prev= curr->left;
				if(!head)
					head = curr->left;
			}
			if(curr->right)
			{
				if(prev)
					prev->next=curr->right;
				prev = curr->right;
				if(!head)
					head = curr->right;
			}
			if(curr->next)
				curr=curr->next;
			else {
				curr = head;
				head = NULL;
				prev = NULL;
			}
		}

    }
};

int main()
{
	Solution sol;
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->left->left = new TreeLinkNode(3);
	root->right = new TreeLinkNode(5);
	root->right->right = new TreeLinkNode(8);
	sol.connect(root);
	TreeLinkNode *temp = root;
	cout<<"Level 0: ";
	while(temp)
	{
		cout<<temp->val;
		temp=temp->next;
	}
	cout<<endl;
	cout<<"Level 1: ";temp=root->left;
	while(temp)
	{
		cout<<temp->val;
		temp=temp->next;
	}
	cout<<endl;
	cout<<"Level 2: ";temp = root->left->left;
	while(temp)
	{
		cout<<temp->val;
		temp=temp->next;
	}
	cout<<endl;
	return 0;
}
