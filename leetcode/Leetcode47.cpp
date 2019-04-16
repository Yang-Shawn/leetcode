#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	int isVisted[20] = { 0 };
	void calFreq(vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++)
			isVisted[nums[i] + 10]++;
	}
	void generatePermuteUnique(vector<int> &nums, vector<int> &c) {
		if (c.size() == nums.size()) {
			res.push_back(c);
			//se.insert(c);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (isVisted[nums[i] + 10] > 0) {
				c.push_back(nums[i]);
				isVisted[nums[i] + 10]--;
				generatePermuteUnique(nums, c);
				c.pop_back();
				isVisted[nums[i] + 10]++;
			}
		}
		return;
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		res.clear();
		if (nums.empty())
			return res;
		vector<int> c;
		calFreq(nums);
		generatePermuteUnique(nums, c);
		set<vector<int>> se(res.begin(), res.end());
		res.assign(se.begin(), se.end());
		//copy(se.begin(), se.end(), back_inserter(res));
		return res;
	}
};
//int main() {
//	vector<int> num = { 3,3,1};
//	vector<vector<int>> res = Solution().permuteUnique(num);
//	for (int i = 0; i < res.size(); i++) {
//		for (int j = 0; j < res[i].size(); j++) {
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}