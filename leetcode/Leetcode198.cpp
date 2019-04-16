#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
//private:
//	vector<int> memo;
//
//	int tryMax(vector<int>& nums, int start) {
//		if (memo[start] != -1) {
//			return memo[start];
//		}
//		if (start >= nums.size())
//			return 0;
//		if (start == nums.size() - 1) {
//			memo[start] = nums[start];
//			return memo[start];
//		}
//		if (start == nums.size() - 2) {
//			memo[start] = max(nums[start], nums[start + 1]);
//			return memo[start];
//		}
//		return max(nums[start] + tryMax(nums, start + 2), nums[start + 1] + tryMax(nums, start + 3));
//	}
public:
	int rob(vector<int>& nums) {
		vector<int>memo(nums.size(), -1);
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		memo[nums.size() - 1] = nums[nums.size() - 1];
		memo[nums.size() - 2] = max(nums[nums.size() - 2], nums[nums.size() - 1]);
		for (int i = nums.size() - 3; i >= 0; i--) {
			memo[i] = max(nums[i] + memo[i + 2], memo[i + 1]);
		}
		return memo[0];
	}
};

//int main() {
//	int num[] = { 2,7,9,3,1 };
//	vector<int> vec(num, num + sizeof(num) / sizeof(int));
//	int res = Solution().rob(vec);
//	cout << res << endl;
//	return 0;
//}