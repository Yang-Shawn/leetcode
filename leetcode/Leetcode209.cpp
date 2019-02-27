#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int res = nums.size() + 1;
		int sum = 0;
		int i = 0, j = -1;
		while (i < nums.size()) {
			if (j + 1 < nums.size() && sum < s) 
				sum = sum + nums[++j];
			else {
				sum = sum - nums[i++];
			}
			if(sum >= s)
				res = min(res, j - i + 1);
		}
		if (res == nums.size() + 1) {
			return 0;
		}
		else
			return res;	
	}
};

//int main() {
//	int num[] = { 2,3,1,2,4,3 };
//	int tar = 8;
//	vector<int> vec(num, num + sizeof(num) / sizeof(int));
//	int res = Solution().minSubArrayLen(tar, vec);
//	cout << res << endl;
//	
//	return 0;
//}