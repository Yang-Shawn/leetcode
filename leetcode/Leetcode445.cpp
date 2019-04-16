#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList445(int arr[], int n) {
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

void printLinkedList445(ListNode* head) {
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
		if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;
		
		stack<int> s1, s2;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		while (cur1 != NULL && cur2 != NULL) {
			s1.push(cur1->val);
			s2.push(cur2->val);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		while (cur1 != NULL) {
			s1.push(cur1->val);
			cur1 = cur1->next;
		}
		while (cur2 != NULL) {
			s2.push(cur2->val);
			cur2 = cur2->next;
		}
		stack<int> res;
		int pre = 0;
		int value = 0;
		while (!s1.empty() && !s2.empty()) {
			value = (s1.top() + s2.top() + pre) % 10;
			res.push(value);
			pre = (s1.top() + s2.top() + pre) / 10;
			s1.pop();
			s2.pop();
		}
		bool judge = s1.empty() ? false : true;
		while (!s1.empty()) {
			value = (s1.top() + pre) % 10;
			res.push(value);
			pre = (s1.top() + pre) / 10;
			s1.pop();
		}
		while (!s2.empty()) {
			value = (s2.top() + pre) % 10;
			res.push(value);
			pre = (s2.top() + pre) / 10;
			s2.pop();
		}
		if (pre == 1)
			res.push(1);
		if (judge) {
			ListNode* pre = NULL;
			cur1 = l1;
			while (cur1 != NULL) {
				cur1->val = res.top();
				pre = cur1;
				cur1 = cur1->next;
				res.pop();
			}
			if (!res.empty()) {
				ListNode* last = new ListNode(res.top());
				last->next = NULL;
				pre->next = last;
			}
			return l1;
		}
		else {
			ListNode* pre = NULL;
			cur2 = l2;
			while (cur2 != NULL) {
				cur2->val = res.top();
				pre = cur2;
				cur2 = cur2->next;
				res.pop();
			}
			if (res.size() != 0) {
				ListNode* last = new ListNode(res.top());
				last->next = NULL;
				pre->next = last;
			}
			return l2;
		}
	}
};
//int main() {
//	int arr1[] = { 5 };
//	int arr2[] = { 5 };
//	int n1 = sizeof(arr1) / sizeof(int);
//	int n2 = sizeof(arr2) / sizeof(int);
//	ListNode* head1 = createLinkedList445(arr1, n1);
//	ListNode* head2 = createLinkedList445(arr2, n2);
//	ListNode* head3 = Solution().addTwoNumbers(head1, head2);
//	printLinkedList445(head3);
//	return 0;
//}