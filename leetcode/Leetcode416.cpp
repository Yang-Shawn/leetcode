#include <iostream>
#include <vector>
using namespace std;

class Solution {
	vector<vector<int>> memo;
private:
	bool tryPartition(vector<int>& nums, int index, int sum) {
		if (sum == 0)
			return true;
		if (index < 0 || sum < 0)
			return false;
		if (memo[index][sum] != -1)
			return memo[index][sum] == 1;

		memo[index][sum] = (tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;
		return memo[index][sum] == 1;
	}
	bool dpPartition(vector<int>& nums, int sum) {
		int n = nums.size();
		vector<bool> dpmemo(sum + 1, false);
		for (int j = 0; j <= sum; j++)
			dpmemo[j] = j == nums[0] ? true : false;
		for (int i = 1; i < nums.size(); i++)
			for (int j = sum; j >= 0; j--)
				if (j >= nums[i])
					dpmemo[j] = dpmemo[j] || dpmemo[j - nums[i]];
		return dpmemo[sum];
	}
public:
	bool canPartition(vector<int>& nums) {
		if (nums.empty())
			return false;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum % 2 != 0)
			return false;
		memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
		//递归解法 记忆化搜索
		//return tryPartition(nums, nums.size() - 1, sum / 2);

		//动态规划
		return dpPartition(nums, sum / 2);
	}
};