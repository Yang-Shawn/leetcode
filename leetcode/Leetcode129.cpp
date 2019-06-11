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
	vector<int> res;
	void calculateSum(TreeNode* root, int num) {
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
			res.push_back(num * 10 + root->val);
		else {
			calculateSum(root->left, num * 10 + root->val);
			calculateSum(root->right, num * 10 + root->val);
		}
	}
public:
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		calculateSum(root, 0);
		for (int i = 0; i < res.size(); i++)
			sum += res[i];
		return sum;
	}
};