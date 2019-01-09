#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> res = nums1;
		int i = 0, j = 0;
		while (i < m && j < n ) {
			if (nums1[i] < nums2[j]) {
				res[i + j] = nums1[i];
				i++;
			}
			else {
				res[i + j] = nums2[j];
				j++;
			}
		}
		while (i < m) {
			res[i + j] = nums1[i];
			i++;
		}
		while (j < n) {
			res[i + j] = nums2[j];
			j++;
		}
		nums1 = res;
	}
};
//int main() {
//	int m = 6, n = 4;
//	int num1[] = { 1, 2, 3, 5, 6, 8, 0, 0, 0, 0 };
//	int num2[] = { 2, 4, 7, 9 };
//	vector<int> vec1(num1, num1 + sizeof(num1) / sizeof(int));
//	vector<int> vec2(num2, num2 + sizeof(num2) / sizeof(int));
//	Solution().merge(vec1, m, vec2, n);
//
//	for (int i = 0; i < vec1.size(); i++) {
//		cout << vec1[i] << " ";
//	}
//
//	return 0;
//}