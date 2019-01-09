#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = -1, two = nums.size();
		for (int i = zero + 1; i < two; ) {
			if (nums[i] == 0)
				swap(nums[++zero], nums[i++]);
			else if (nums[i] == 2)
				swap(nums[i], nums[--two]);
			else
				i++;
		}
	}
};

//int main() {
//	int num1[] = { 2,0,2,1,1,0 };
//	vector<int> vec1(num1, num1 + sizeof(num1) / sizeof(int));
//	Solution().sortColors(vec1);
//
//	for (int i = 0; i < vec1.size(); i++) {
//		cout << vec1[i] << " ";
//	}
//
//	return 0;
//}