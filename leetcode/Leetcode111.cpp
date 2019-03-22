#include <iostream>
#include <vector>
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
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		if (root->left && root->right) {
			int leftDepth = minDepth(root->left);
			int rightDepth = minDepth(root->right);
			return min(leftDepth, rightDepth) + 1;
		}
		else if (root->right) {
			int rightDepth = minDepth(root->right);
			return rightDepth + 1;
		}
		else {
			int leftDepth = minDepth(root->left);
			return leftDepth + 1;
		}

	}
};