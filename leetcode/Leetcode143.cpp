#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return;
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
		while (cur != mid && pre != NULL) {
			ListNode* next1 = cur->next;
			ListNode* next2 = pre->next;

			cur->next = pre;
			pre->next = next1;

			cur = next1;
			pre = next2;
		}

		cur->next = pre;

		delete dummyNode;
		return;
	}
};