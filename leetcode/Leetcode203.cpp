#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList203(int arr[], int n) {
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

void printLinkedList203(ListNode* head) {
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
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return NULL;

		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode* preNode = dummyNode;
		ListNode* curNode = head;
		ListNode* nextNode = head->next;
		while (curNode != NULL) {
			nextNode = curNode->next;
			if (curNode->val == val) {
				preNode->next = nextNode;
				delete curNode;
				curNode = nextNode;
			}
			else {
				preNode->next = curNode;
				preNode = curNode;
				curNode = nextNode;
			}
		}
		ListNode* res = dummyNode->next;
		delete dummyNode;
		return res;
	}
};

//int main() {
//	int arr[] = { 5,1,2,3,4,5,5,6,7,8,5 };
//	int n = sizeof(arr) / sizeof(int);
//	int val = 5;
//	ListNode* head = createLinkedList203(arr, n);
//	ListNode* head2 = Solution().removeElements(head, val);
//	printLinkedList203(head2);
//	return 0;
//}