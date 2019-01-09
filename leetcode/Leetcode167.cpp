#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
		while (numbers[i] + numbers[j] != target) {
			if (numbers[i] + numbers[j] < target)
				i++;
			else if (numbers[i] + numbers[j] != target)
				j--;
		}
		int num[2] = { i + 1 , j + 1 };
		vector<int> vec(num, num + sizeof(num) / sizeof(int));
		return vec;
	}
};

//int main() {
//	int k = 9;
//	int num1[] = { 2,7,11,15 };
//	vector<int> vec1(num1, num1 + sizeof(num1) / sizeof(int));
//	vector<int> res = Solution().twoSum(vec1, k);
//
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << " ";
//	}
//
//	return 0;
//}