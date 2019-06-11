#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	// 计算包含节点root的路径和为sum的路径数目
	int subPathSum(TreeNode* root, int sum) {
		int res = 0;
		if (root == NULL)
			return res;
		if (root->val == sum)
			res += 1;
		res += subPathSum(root->left, sum - root->val);
		res += subPathSum(root->right, sum - root->val);
		return res;
	}
public:
	int pathSum(TreeNode* root, int sum) {
		int res = 0;
		if (root == NULL)
			return res;

		res += subPathSum(root, sum);
		res += pathSum(root->left, sum);
		res += pathSum(root->right, sum);

		return res;
	}
};