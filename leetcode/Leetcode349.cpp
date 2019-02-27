#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> record(nums1.begin(), nums1.end());
		set<int> result;
		for (int i = 0; i < nums2.size(); i++) {
			if (record.find(nums2[i]) != record.end()) {
				result.insert(nums2[i]);
			}
		}
		vector<int> res;
		for (set<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
			res.push_back(*iter);
		}
		return res;
	}
};

//int main() {
//	int num1[] = { 0, 2, 5, 6, 8, 5, 4, 6, 3, 2, 1 };
//	int num2[] = { 2, 5, 4, 9 };
//	vector<int> vec1(num1, num1 + sizeof(num1) / sizeof(int));
//	vector<int> vec2(num2, num2 + sizeof(num2) / sizeof(int));
//	vector<int> result = Solution().intersection(vec1, vec2);
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << " ";
//	}
//	return 0;
//}