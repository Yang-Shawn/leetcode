#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < lists.size(); i++) {
			ListNode* cur = lists[i];
			while (cur != NULL) {
				pq.push(cur->val);
				cur = cur->next;
			}
		}
		ListNode* dummyNode = new ListNode(-1);
		ListNode* pre = dummyNode;
		while (!pq.empty()) {
			ListNode * cur = new ListNode(pq.top());
			pq.pop();
			pre->next = cur;
			pre = cur;
		}
		return dummyNode->next;
	}
};