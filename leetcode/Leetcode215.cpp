#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		int num = nums.size() - k;
		KthSort(nums, left, right, num);
		return nums[num];
	}
	void KthSort(vector<int>& num, int left, int right, int k) {
		if (left < right) {
			int i = left, j = right;
			int key = num[left];
			while (i < j) {
				while (num[j] > key && i < j)
					j--;
				if (i < j)
					num[i++] = num[j];
				while (num[i] < key && i < j)
					i++;
				if (i < j)
					num[j--] = num[i];
			}

			num[i] = key;

			if (i > k)
				KthSort(num, left, i - 1, k);
			else if (i < k)
				KthSort(num, i + 1, right, k);
		}
	}
};

//int main() {
//	int k = 3;
//	int num1[] = { 2,0,2,1,1,0 };
//	vector<int> vec1(num1, num1 + sizeof(num1) / sizeof(int));
//	int res = Solution().findKthLargest(vec1, k);
//	cout << res << endl;
//	for (int i = 0; i < vec1.size(); i++) {
//		cout << vec1[i] << " ";
//	}
//
//	return 0;
//}