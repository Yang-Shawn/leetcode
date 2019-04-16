#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	vector<bool> visit;
	void generateSubsets(vector<int>& nums, int start, vector<int>& c) {
		if (start == nums.size()) {
			res.push_back(c);
			return;
		}
		if (start > 0 && nums[start] == nums[start - 1] && !visit[start - 1]) {
			generateSubsets(nums, start + 1, c);
		}
		else {

			c.push_back(nums[start]);
			visit[start] = true;
			generateSubsets(nums, start + 1, c);
			c.pop_back();
			visit[start] = false;

			generateSubsets(nums, start + 1, c);
		}
		return;
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		res.clear();
		if (nums.size() == 0)
			return res;

		visit = vector<bool>(nums.size(), false);
		sort(nums.begin(), nums.end());
		vector<int> c;
		generateSubsets(nums, 0, c);
		return res;
	}
};