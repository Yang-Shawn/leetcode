#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL && q != NULL)
			return false;
		if (p != NULL && q == NULL)
			return false;
		bool leftSame = isSameTree(p->left, q->left);
		bool rightSame = isSameTree(p->right, q->right);
		if (leftSame && rightSame && p->val == q->val)
			return true;
		else
			return false;
	}
};