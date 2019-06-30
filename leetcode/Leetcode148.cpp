#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	// 快速排序实现
	void qswap(int *a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	ListNode* qsort(ListNode* nbegin, ListNode* nend) {
		if (nbegin == nend || nbegin->next == nend)
			return nbegin;
		int value = nbegin->val;
		ListNode* p = nbegin; 
		ListNode* q = nbegin;
		while (q != nend) {
			if (q->val < value) {
				p = p->next;
				qswap(&p->val, &q->val);
			}
			q = q->next;
		}
		qswap(&p->val, &nbegin->val);
		return p;
	}
	void quicksort(ListNode* nbegin, ListNode* nend) {
		if (nbegin == nend || nbegin->next == nend)
			return;
		ListNode* mid = qsort(nbegin, nend);
		quicksort(nbegin, mid);
		quicksort(mid->next, nend);
	}

	//归并排序实现
	ListNode* mergesort(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* midNode = getMid(head);
		ListNode* head1 = mergesort(head);
		ListNode* head2 = mergesort(midNode);
		return merge(head1, head2);
	}

	ListNode* merge(ListNode* head1, ListNode* head2) {
		ListNode* dummyNode = new ListNode(-1);
		ListNode* pre = dummyNode;
		while (head1 != NULL && head2 != NULL) {
			if (head1->val <= head2->val) {
				pre->next = head1;
				head1 = head1->next;
			}
			else {
				pre->next = head2;
				head2 = head2->next;
			}
			pre = pre->next;
		}
		if (head1 != NULL)
			pre->next = head1;
		else if (head2 != NULL)
			pre->next = head2;

		ListNode* resNode = dummyNode->next;
		delete dummyNode;
		return resNode;
	}

	ListNode* getMid(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode* cur1 = head;
		ListNode* cur2 = head;
		ListNode* pre = head;

		while (cur2->next != NULL && cur2->next->next != NULL) {
			pre = cur1;
			cur1 = cur1->next;
			cur2 = cur2->next->next;
		}
		if (cur2->next != NULL) {
			pre = cur1;
			cur1 = cur1->next;
		}
		pre->next = NULL;
		return cur1;
	}

public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		// 使用快速排序实现
		quicksort(head, NULL);
		return head;

		// 使用归并排序实现
		//return mergesort(head);
	}
};