#include <iostream>
#include <math.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList2(long arr[], int n) {
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

void deleteLinkedList2(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		ListNode* delNode = curNode;
		curNode = curNode->next;
		delete delNode;
	}
	return;
}

void printLinkedList2(ListNode* head) {
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0, pre = 0;
		ListNode* curNode1 = l1;
		ListNode* curNode2 = l2;

		sum = (curNode1->val + curNode2->val + pre) % 10;
		pre = (curNode1->val + curNode2->val + pre) / 10;
		ListNode* head = new ListNode(sum);
		ListNode* curNode = head;

		curNode1 = curNode1->next;
		curNode2 = curNode2->next;
		while (curNode1 != NULL && curNode2 != NULL) {
			sum = (curNode1->val + curNode2->val + pre) % 10;
			pre = (curNode1->val + curNode2->val + pre) / 10;
			ListNode* newNode = new ListNode(sum);

			curNode->next = newNode;
			curNode = newNode;

			curNode1 = curNode1->next;
			curNode2 = curNode2->next;
		}

		while (curNode1 != NULL) {
			sum = (curNode1->val + pre) % 10;
			pre = (curNode1->val + pre) / 10;
			ListNode* newNode = new ListNode(sum);

			curNode->next = newNode;
			curNode = newNode;

			curNode1 = curNode1->next;
		}

		while (curNode2 != NULL) {
			sum = (curNode2->val + pre) % 10;
			pre = (curNode2->val + pre) / 10;
			ListNode* newNode = new ListNode(sum);

			curNode->next = newNode;
			curNode = newNode;

			curNode2 = curNode2->next;
		}

		if (pre == 1) {
			ListNode* newNode = new ListNode(1);

			curNode->next = newNode;
		}
	
		return head;
	}
};

//int main() {
//	long arr1[] = { 9,9,9,9,9,9,9,9,9,9 };
//	long arr2[] = { 9,9,9,9,9,9,9,9,9,9 };
//	int n1 = sizeof(arr1) / sizeof(long);
//	int n2 = sizeof(arr2) / sizeof(long);
//
//	ListNode* L1 = createLinkedList2(arr1, n1);
//	ListNode* L2 = createLinkedList2(arr2, n2);
//
//	ListNode* head = Solution().addTwoNumbers(L1, L2);
//	printLinkedList2(head);
//
//	return 0;
//}