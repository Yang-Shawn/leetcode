#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList24(int arr[], int n) {
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

void printLinkedList24(ListNode* head) {
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
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;

		if (head == NULL || head->next == NULL)
			return head;

		ListNode* node1 = head;
		ListNode* node2 = head->next;
		ListNode* preNode = dummyNode;
		ListNode* nextNode = node2->next;

		preNode->next = node2;
		node2->next = node1;
		node1->next = nextNode;
		preNode = node1;

		while (preNode->next != NULL && preNode->next->next != NULL) {
			node1 = preNode->next;
			node2 = node1->next;
			nextNode = node2->next;

			preNode->next = node2;
			node2->next = node1;
			node1->next = nextNode;
			preNode = node1;
		}
		
		ListNode* head2 = dummyNode->next;
		delete dummyNode;
		return head2;
	}
};

//int main() {
//	int arr[] = {0};
//	int n = sizeof(arr) / sizeof(int);
//	ListNode* head = createLinkedList24(arr, n);
//	ListNode* res = Solution().swapPairs(head);
//	printLinkedList24(res);
//
//	return 0;
//}