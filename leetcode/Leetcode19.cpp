#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList19(int arr[], int n) {
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

void printLinkedList19(ListNode* head) {
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL)
			return head;
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode* preNode = dummyNode;
		ListNode* curNode = head;
		while (n-- > 0 && curNode != NULL)
			curNode = curNode->next;
		while (curNode != NULL) {
			preNode = preNode->next;
			curNode = curNode->next;
		}
		ListNode* delNode = preNode->next;
		preNode->next = delNode->next;
		ListNode* head2 = dummyNode->next;
		delete delNode;
		delete dummyNode;
		return head2;
	}
};

//int main() {
//	int arr[] = { 1 };
//	int len = sizeof(arr) / sizeof(int);
//	int n = 1;
//	ListNode* head = createLinkedList19(arr, len);
//	ListNode* head2 = Solution().removeNthFromEnd(head, n);
//	printLinkedList19(head2);
//	return 0;
//}