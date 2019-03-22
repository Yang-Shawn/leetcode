#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Command {
	string s; //go, print
	TreeNode* node;
	Command(string str, TreeNode* n) : s(str), node(n) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<Command*> sta;

		if (root == NULL)
			return res;

		Command* r = new Command("go", root);
		sta.push(r);

		while (!sta.empty()) {
			Command* cur = sta.top();
			sta.pop();
			if (cur->s == "print")
				res.push_back(cur->node->val);
			else {
				sta.push(new Command("print", cur->node));

				if (cur->node->right)
					sta.push(new Command("go", cur->node->right));

				if (cur->node->left)
					sta.push(new Command("go", cur->node->left));
			}
		}
		return res;
	}
};