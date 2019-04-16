#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
	bool Comp(TreeNode* node1, TreeNode* node2) {
		if (node1 == NULL && node2 == NULL)
			return true;
		else if (node1 == NULL && node2 != NULL)
			return false;
		else if (node1 != NULL && node2 == NULL)
			return false;

		bool res1 = Comp(node1->left, node2->right);
		bool res2 = Comp(node1->right, node2->left);

		if (node1->val == node2->val && res1 &&res2)
			return true;
		else
			return false;
	}
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return Comp(root->left, root->right);
	}
};