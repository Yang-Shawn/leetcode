#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	// 
	void generateSubsets(vector<int>& nums, int sum, int index, vector<int>& c) {
		if (c.size() == sum) {
			res.push_back(c);
			return;
		}
		for (int i = index; i < nums.size(); i++) {
			c.push_back(nums[i]);
			generateSubsets(nums, sum, i + 1, c);
			c.pop_back();
		}
		return;
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		res.clear();
		if (nums.size() == 0)
			return res;
		for (int i = 0; i <= nums.size(); i++) {
			vector<int> c;
			generateSubsets(nums, i, 0, c);
		}
		return res;
	}
};