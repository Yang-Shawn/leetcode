#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node->next == NULL) {
			node = NULL;
		}
		else {
			ListNode * delNode = node->next;
			node->val = delNode->val;
			node->next = delNode->next;
			delete delNode;
		}

	}
};