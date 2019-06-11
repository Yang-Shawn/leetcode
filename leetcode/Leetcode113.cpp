#include<iostream>
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
	vector<vector<int>> pathSum1(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> sub;
		if (root == NULL)
			return res;
		if (root->left == NULL && root->right == NULL && root->val == sum) {
			sub.push_back(root->val);
			res.push_back(sub);
			return res;
		}
		vector<vector<int>> left = pathSum1(root->left, sum - root->val);
		if (left.size() != 0) 
			for (int i = 0; i < left.size(); i++) {
				left[i].push_back(root->val);
				res.push_back(left[i]);
			}
			
		vector<vector<int>> right = pathSum1(root->right, sum - root->val);
		if (right.size() != 0)
			for (int i = 0; i < right.size(); i++) {
				right[i].push_back(root->val);
				res.push_back(right[i]);
			}

		return res;
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res = pathSum1(root, sum);
		for (int i = 0; i < res.size(); i++) 
			for (int j = 0; j < res[i].size() / 2; j++) 
				swap(res[i][j], res[i][res[i].size() - 1 - j]);
			
		return res;
	}
};