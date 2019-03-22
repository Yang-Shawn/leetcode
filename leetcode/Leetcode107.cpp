#include <iostream>
#include <vector>
#include <stack>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;

		queue<pair<TreeNode*, int>> q;
		q.push(make_pair(root, 0));

		stack<pair<TreeNode*, int>> s;

		while (!q.empty()) {
			TreeNode* node = q.front().first;
			int level = q.front().second;
			s.push(make_pair(node, level));
			q.pop();

			if (node->right)
				q.push(make_pair(node->right, level + 1));
			if (node->left)
				q.push(make_pair(node->left, level + 1));
		}

		int num = s.top().second;
		while (!s.empty()) {
			TreeNode* node = s.top().first;
			int level = s.top().second;
			s.pop();
			if (num - level == res.size())
				res.push_back(vector<int>());
			res[num - level].push_back(node->val);
		}
		return res;
	}
};