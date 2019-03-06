#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int n) : val(n), next(NULL) {}
};

ListNode* creatListNode(int arr[], int n) {
	if (n == 0)
		return NULL;
	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i < n; i++) {
		ListNode* nextNode = new ListNode(arr[i]);
		curNode->next = nextNode;
		curNode = nextNode;
	}
	return head;
}

void deleteListNode(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		ListNode* delNode = curNode;
		curNode = curNode->next;
		delete delNode;
	}
	return;
}

void printListNode(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		cout << curNode->val << " -> ";
		curNode = curNode->next;
	}
	cout << "NULL" << endl;
}

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;
		int val = m;
		ListNode* curNode = head;
		ListNode* preNode1 = head;
		ListNode* nextNode1 = NULL;
		while (--m > 0) {
			preNode1 = curNode;
			curNode = curNode->next;
			n--;
		}

		ListNode* preNode2 = curNode;
		ListNode* preNode = preNode1;
		ListNode* nextNode = NULL;
		while (--n > 0) {
			nextNode = curNode->next;
			curNode->next = preNode;
			preNode = curNode;
			curNode = nextNode;
		}
		nextNode1 = curNode->next;
		curNode->next = preNode;
		if (val == 1)
			head = curNode;
		else
			preNode1->next = curNode;

		preNode2->next = nextNode1;

		return head;
	}
};

//int main() {
//	int arr[] = { 1, 2};
//	int len = sizeof(arr) / sizeof(int);
//
//	ListNode* head = creatListNode(arr, len);
//	printListNode(head);
//
//	int m = 1, n = 2;
//	ListNode* head2 = Solution().reverseBetween(head, m, n);
//	printListNode(head2);
//
//    deleteListNode(head2);
//	getchar();
//	return 0;
//}