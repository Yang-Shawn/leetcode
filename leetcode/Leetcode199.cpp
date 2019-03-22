#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;

		queue<pair<TreeNode*, int>> q;
		q.push(make_pair(root, 0));

		while (!q.empty()) {
			TreeNode* node = q.front().first;
			int level = q.front().second;
			q.pop();

			if (level == res.size()) {
				res.push_back(node->val);
			}

			if (node->right)
				q.push(make_pair(node->right, level + 1));
			if (node->left)
				q.push(make_pair(node->left, level + 1));
		}
		return res;
	}
};