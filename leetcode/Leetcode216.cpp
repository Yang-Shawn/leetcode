#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	void generateCombinationSum3(int k, int target, int index, vector<int>& c) {
		if (target < 0)
			return;
		if (c.size() == k) {
			if (target == 0) {
				res.push_back(c);
				return;
			}
			return;
		}
		for (int i = index; i <= 9; i++) {
			c.push_back(i);
			generateCombinationSum3(k, target - i, i + 1, c);
			c.pop_back();
		}
		return;
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> c;
		generateCombinationSum3(k, n, 1, c);
		return res;
	}
};