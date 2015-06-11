#include<iostream>
#include<stdio>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	void reverseList(ListNode *start, *end)
	{
		
	}

    ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *next=NULL, *curr = NULL;
		curr = head;
		int count;
		prev = NULL;
		if(!head or k<=1)
			return head;
		while(curr)
		{
			count++;
			if(count==k)
				reverseList(prev, curr);
			curr = curr->next;
		}
		
    }
};

int main()
{
	Solution sol;
	ListNode *head  = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head = reverseKGroup(head, 2);
	while(head)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	return 0;
}
