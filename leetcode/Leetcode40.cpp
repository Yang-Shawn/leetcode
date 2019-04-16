#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*now:����Ԫ��֮��
	  p:��pλ��֮������µ�Ԫ��
	  chs:ÿһ�������
	  cans:ԭ����
	  used:��¼ĳ��Ԫ���Ƿ�ʹ�ù�
	*/
	void DFS(int now, int p, int target, vector<int>& chs, vector<int>& cans, vector<int>& used, vector<vector<int>>& result) {
		if (now == target) {
			result.push_back(chs);
			return;
		}
		for (int i = p + 1; i < cans.size(); i++) {
			if (now + cans[i] > target)
				return;
			if (i && cans[i] == cans[i - 1] && !used[i - 1])
				continue;
			used[i] = 1;
			chs.push_back(cans[i]);
			DFS(now + cans[i], i, target, chs, cans, used, result);
			used[i] = 0;
			chs.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> chs;
		vector<vector<int>> result;

		if (target == 0)
			return result;

		sort(candidates.begin(), candidates.end());//��ԭ�������������

		vector<int> used = vector<int>(candidates.size(), 0);
		DFS(0, -1, target, chs, candidates, used, result);
		return result;
	}
};

//int main() {
//	int arr[] = { 2,3,6,7,1,2,4 };
//	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
//	int tar = 8;
//	vector<vector<int>> res = Solution().combinationSum2(vec, tar);
//	for (int i = 0; i < res.size(); i++) {
//		for (int j = 0; j < res[i].size(); j++) {
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}