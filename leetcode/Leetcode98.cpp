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
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		bool judge = true;

		TreeNode* max = root->left;
		while (max && max->right != NULL)
			max = max->right;

		TreeNode* min = root->right;
		while (min && min->left != NULL)
			min = min->left;

		if (max && max->val >= root->val)
			judge = false;
		if (min && min->val <= root->val)
			judge = false;

		return isValidBST(root->left) && isValidBST(root->right) && judge;
	}
};