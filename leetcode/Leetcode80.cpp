#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		else {
			int pre1 = nums[0], pre2 = nums[1];
			int k = 2;
			for (int i = 2; i < nums.size(); i++) {
				if ((nums[i] != pre2) || (nums[i] != pre1)) {
					pre1 = pre2;
					pre2 = nums[i];
					if (i != k) {
						nums[k] = nums[i];
						k++;
					}
					else
						k++;
				}
			}
			return k;
		}
	}
};
//int main() {
//	int num[] = {0,0,1,1,1,2,2,2,3,4,4,5,5,5,6,6,7};
//	vector<int> vec(num, num + sizeof(num) / sizeof(int));
//	int res = Solution().removeDuplicates(vec);
//	cout << res << endl;
//	for (int i = 0; i < vec.size(); i++) {
//		cout << vec[i] << " ";
//	}
//	return 0;
//}