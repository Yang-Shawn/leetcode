#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList21(int arr[], int n) {
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

void printLinkedList21(ListNode* head) {
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = NULL;

		ListNode* curNode1 = l1;
		ListNode* curNode2 = l2;
		if (curNode1->val > curNode2->val) {
			dummyNode->next = curNode2;
			curNode2 = curNode2->next;
		}
		else {
			dummyNode->next = curNode1;
			curNode1 = curNode1->next;
		}

		ListNode* curNode = dummyNode->next;

		while (curNode1 != NULL && curNode2 != NULL) {
			if (curNode1->val > curNode2->val) {
				curNode->next = curNode2;
				curNode = curNode->next;
				curNode2 = curNode2->next;
			}
			else {
				curNode->next = curNode1;
				curNode = curNode->next;
				curNode1 = curNode1->next;
			}
		}
		if (curNode1 != NULL) {
			curNode->next = curNode1;
		}
		else {
			curNode->next = curNode2;
		}

		ListNode* head = dummyNode->next;
		delete dummyNode;
		return head;
	}
};

//int main() {
//	int arr1[] = { 1,4,5,6,9 };
//	int arr2[] = { 2,3,4,7,8 };
//	int n1 = sizeof(arr1) / sizeof(int);
//	int n2 = sizeof(arr2) / sizeof(int);
//	ListNode* L1 = createLinkedList21(arr1, n1);
//	ListNode* L2 = createLinkedList21(arr2, n2);
//
//	ListNode* head = Solution().mergeTwoLists(L1, L2);
//	printLinkedList21(head);
//
//	return 0;
//}