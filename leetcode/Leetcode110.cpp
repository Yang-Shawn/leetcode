#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;

		int leftDepth = Depth(root->left);
		int rightDepth = Depth(root->right);
		if (abs(leftDepth - rightDepth) > 1)
			return false;
		else {
			bool leftB = isBalanced(root->left);
			bool rightB = isBalanced(root->right);
			if (leftB && rightB)
				return true;
			else
				return false;
		}
	}
private:
	int Depth(TreeNode* node) {
		if (node == NULL)
			return 0;
		int ld = Depth(node->left);
		int rd = Depth(node->right);
		return max(ld, rd) + 1;
	}
};
