#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList83(int arr[], int n) {
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

void deleteLinkedList83(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		ListNode* delNode = curNode;
		curNode = curNode->next;
		delete delNode;
	}
	return;
}

void printLinkedList83(ListNode* head) {
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
		ListNode* curNode = head;
		while (curNode != NULL) {
		    ListNode* nextNode = curNode->next;

			while (nextNode != NULL && curNode->val == nextNode->val) {
				curNode->next = nextNode->next;
				nextNode = nextNode->next;
			}

			curNode = curNode->next;
		}
		return head;
	}
};

//int main() {
//	int arr[] = { 1,1,1,1,3,4,5,6,6,6,7,8 };
//	int n = sizeof(arr) / sizeof(int);
//	ListNode* head = createLinkedList83(arr, n);
//	ListNode* head2 = Solution().deleteDuplicates(head);
//	printLinkedList83(head2);
//	return 0;
//}