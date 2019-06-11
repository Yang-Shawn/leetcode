#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return NULL;

		int len = 0;
		ListNode* cur = head;
		while (cur != NULL) {
			cur = cur->next;
			len++;
		}
		k = k % len;
		int j = len - k;

		if (k == 0)
			return head;
		
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode* pre = dummyNode;
		cur = head;
		for (int i = 0; i < j; i++) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = NULL;
		dummyNode->next = cur;

		for (int i = 1; i < k; i++)
			cur = cur->next;
		cur->next = head;

		ListNode* resNode = dummyNode->next;
		delete dummyNode;
		return resNode;
	}
};