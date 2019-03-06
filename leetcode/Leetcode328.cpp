#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int y) : val(y), next(NULL) {}
};

ListNode* createLinkedList328(int arr[], int n) {
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

void printLinkedList328(ListNode* head) {
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
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode* preNode = dummyNode;
		ListNode* curNode = head;
		ListNode* nextNode = curNode->next;
		ListNode* head2 = head->next;

		int len = 1;
		while (nextNode != NULL) {
			preNode = curNode;
			curNode->next = nextNode->next;
			curNode = nextNode;
			nextNode = curNode->next;
			len++;
		}
		if (len % 2 == 0)
			preNode->next = head2;
		else
			curNode->next = head2;

		delete dummyNode;
		return head;
	}
};

//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8 };
//	int n = sizeof(arr) / sizeof(int);
//	ListNode* head = createLinkedList328(arr, n);
//	ListNode* head2 = Solution().oddEvenList(head);
//	printLinkedList328(head2);
//}