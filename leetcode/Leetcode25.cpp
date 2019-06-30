#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode* pre = dummyNode;
		ListNode* cur = head;
		while (cur != NULL) {
			vector<ListNode*> KNode;
			int i;
			for (i = 0; i < k && cur != NULL; i++) {
				KNode.push_back(cur);
				cur = cur->next;
			}

			if (i == k) {
				for (int j = k - 1; j > 0; j--)
					KNode[j]->next = KNode[j - 1];
				KNode[0]->next = cur;
				pre->next = KNode[k - 1];

				pre = KNode[0];
			}

		}
		ListNode* resNode = dummyNode->next;
		delete dummyNode;
		return resNode;
	}
};