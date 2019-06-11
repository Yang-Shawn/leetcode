#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL)
			return NULL;

		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode* pre1 = dummyNode;
		ListNode* cur1 = head;
		ListNode* next1 = cur1->next;

		while (cur1 != NULL) {
			
			ListNode* pre2 = dummyNode;
			ListNode* cur2 = dummyNode->next;
			while (cur2 != cur1 && cur2->val < cur1->val) {
				pre2 = cur2;
				cur2 = cur2->next;
			}
			// 如果cur1之前没有节点值大于cur1的值
			if (cur2 == cur1) {
				pre1 = cur1;
				cur1 = next1;
				if (cur1 == NULL)
					break;
				next1 = cur1->next;
			}
			else { //插入节点
				pre2->next = cur1;
				cur1->next = cur2;

				pre1->next = next1;
				cur1 = next1;
				if (cur1 == NULL)
					break;
				next1 = cur1->next;
			}
		}
		ListNode* resNode = dummyNode->next;
		delete dummyNode;
		return resNode;
	}
};