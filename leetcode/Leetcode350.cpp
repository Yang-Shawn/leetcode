#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> record;
		for (int i = 0; i < nums1.size(); i++) {
			record[nums1[i]]++;
		}
		vector<int> resultVector;
		for (int i = 0; i < nums2.size(); i++) {
			if (record[nums2[i]] > 0) {
				resultVector.push_back(nums2[i]);
				record[nums2[i]]--;
			}
		}
		return resultVector;
	}
};

//int main() {
//	int num1[] = { 4,9,5 };
//	int num2[] = { 9,4,9,8,4 };
//	vector<int> vec1(num1, num1 + sizeof(num1) / sizeof(int));
//	vector<int> vec2(num2, num2 + sizeof(num2) / sizeof(int));
//	vector<int> result = Solution().intersect(vec1, vec2);
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << " ";
//	}
//	return 0;
//}