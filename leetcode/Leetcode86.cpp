#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList86(int arr[], int n) {
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

void deleteLinkedList86(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		ListNode* delNode = curNode;
		curNode = curNode->next;
		delete delNode;
	}
	return;
}

void printLinkedList86(ListNode* head) {
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
	ListNode* partition(ListNode* head, int x) {
		// ²éÕÒ²Î¿¼Öµ

		int refValue = x;

		ListNode* curNode = head;
		ListNode* preNode = new ListNode(0);
		preNode->next = curNode;

		while (curNode != NULL && curNode->val < refValue) {
			preNode = curNode;
			curNode = curNode->next;
		}

		if (curNode == NULL)
			return head;

		if (curNode == head) {
			ListNode* curNode2 = head;
			while (curNode2 != NULL && curNode2->val >= refValue) {
				curNode2 = curNode2->next;
			}
			if (curNode2 == NULL)
				return head;
			else
				head = curNode2;
		}

		ListNode* head2 = curNode;
		ListNode* bigNode = head2;

		curNode = curNode->next;
		preNode->next = curNode;

		while (curNode != NULL) {
			if (curNode->val < refValue) {
				preNode = curNode;
				curNode = curNode->next;
			}
			else {
				bigNode->next = curNode;
				bigNode = curNode;

				curNode = curNode->next;
				preNode->next = curNode;
			}
		}

		bigNode->next = NULL;
		preNode->next = head2;
		
		return head;
	}
};

//int main() {
//	int arr[] = { 2,3,4,3,5,7,1,3,8,3,6 };
//	int num = 3;
//	int n = sizeof(arr) / sizeof(int);
//
//	ListNode* head = createLinkedList86(arr, n);
//	ListNode* res = Solution().partition(head, num);
//	printLinkedList86(res);
//	return 0;
//}