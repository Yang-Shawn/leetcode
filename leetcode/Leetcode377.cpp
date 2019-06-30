#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
	int combinationSum4(vector<int>& nums, int target) {

		if (target <= 0 || nums.size() == 0)
			return 0;

		sort(nums.begin(), nums.end());

		vector<long> vec(target + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= target)
				vec[nums[i]]++;
			else
				break;
		}

		for (int i = 1; i <= target; i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (nums[j] <= i) {
					vec[i] = vec[i] + vec[i - nums[j]];
					if (vec[i] > INT_MAX) 
						vec[i] = 0;
				}
				else
					break;
			}
		}

		return vec[target];
	}
};

//int main() {
//	vector<int> vec = { 3,33,333 };
//	int target = 1000;
//	int res = Solution().combinationSum4(vec, target);
//	cout << res << endl;
//	return 0;
//}