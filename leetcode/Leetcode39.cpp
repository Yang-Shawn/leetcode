#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	void generateCombinationSum(vector<int> &cand, int target, int start, vector<int> &c) {
		if (target == 0) {
			res.push_back(c);
			return;
		}
		for (int i = start; i < cand.size(); i++) {
			if (target < 0)
				break;
			c.push_back(cand[i]);
			generateCombinationSum(cand, target - cand[i], i, c);
			c.pop_back();
		}
		return;
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		res.clear();
		if (candidates.empty())
			return res;
		vector<int> c;
		generateCombinationSum(candidates, target, 0, c);
		return res;
	}
};

//int main() {
//	int arr[] = { 2,3,6,7 };
//	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
//	int tar = 8;
//	vector<vector<int>> res = Solution().combinationSum(vec, tar);
//	for (int i = 0; i < res.size(); i++) {
//		for (int j = 0; j < res[i].size(); j++) {
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}