#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	bool isVisted[20] = { false };
	void generatePermute(vector<int> &nums, vector<int> &c) {
		if (c.size() == nums.size()) {
			res.push_back(c);
			//cout << "res push" << endl;
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!isVisted[nums[i] + 10]) {
				c.push_back(nums[i]);
				//cout << "c push" << nums[i] << endl;
				isVisted[nums[i] + 10] = true;

				generatePermute(nums, c);

				//cout << "c pop" << endl;
				c.pop_back();
				//cout << "false" << nums[i] << endl;
				isVisted[nums[i] + 10] = false;
			}
		}
		return;
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		res.clear();
		if (nums.empty())
			return res;
		vector<int> c;
		generatePermute(nums, c);
		return res;
	}
};

//int main() {
//	vector<int> num = {-1,2,-3,4};
//	vector<vector<int>> res = Solution().permute(num);
//	for (int i = 0; i < res.size(); i++) {
//		for (int j = 0; j < res[i].size(); j++) {
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}