#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList82(int arr[], int n) {
	if (n == 0)
		return NULL;
	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i < n; i++) {
		ListNode* newNode = new ListNode(arr[i]);
		curNode->next = newNode;
		curNode = newNode;
	}
	return head;
}

void printLinkedList82(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		cout << curNode->val << " -> ";
		curNode = curNode->next;
	}
	cout << "NULL" << endl;
	return;
}

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		//ÐéÄâÍ·½Úµã
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode* preNode = dummyNode;
		ListNode* curNode = head;
		ListNode* nextNode = head->next;

		while (curNode != NULL) {
			nextNode = curNode->next;
			if (nextNode != NULL && curNode->val == nextNode->val) {
				while (nextNode != NULL && curNode->val == nextNode->val) {
					curNode->next = nextNode->next;
					delete nextNode;
					nextNode = curNode->next;
				}
				delete curNode;
				preNode->next = nextNode;
				curNode = nextNode;
			}
			else {
				preNode->next = curNode;
				preNode = preNode->next;
				curNode = nextNode;
			}
		}

		ListNode* res = dummyNode->next;
		delete dummyNode;
		return res;
	}
};

//int main() {
//	int arr[] = { 1,1,2,2,2,8,8};
//	int n = sizeof(arr) / sizeof(int);
//	ListNode* head = createLinkedList82(arr, n);
//	ListNode* res = Solution().deleteDuplicates(head);
//	printLinkedList82(res);
//}