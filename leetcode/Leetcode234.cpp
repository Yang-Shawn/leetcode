#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode* mid = dummyNode;
		ListNode* cur = dummyNode;

		while (cur->next != NULL && cur->next->next != NULL) {
			mid = mid->next;
			cur = cur->next->next;
		}
		if (cur->next != NULL) {
			mid = mid->next;
		}

		ListNode* pre = NULL;
		cur = mid->next;
		while (cur != NULL) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		cur = head;
		while (pre != NULL) {
			if (cur->val != pre->val)
				return false;
			cur = cur->next;
			pre = pre->next;
		}
		return true;
	}
};