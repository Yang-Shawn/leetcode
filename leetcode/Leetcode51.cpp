#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<string>> result;
	vector<vector<int>> res;
	void generateNQueens(int n, int x, vector<int>& c, vector<bool>& listy, vector<bool>& list1, vector<bool>& list2) {
		if (x == n) {
			res.push_back(c);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!listy[i] && !list1[x + i] && !list2[x - i + n - 1]) {
				c.push_back(i);
				listy[i] = true;
				list1[x + i] = true;
				list2[x - i + n - 1] = true;
				generateNQueens(n, x + 1, c, listy, list1, list2);
				c.pop_back();
				listy[i] = false;
				list1[x + i] = false;
				list2[x - i + n - 1] = false;
			}
		}
		return;
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		result.clear();
		if (n <= 0)
			return result;
		if (n == 1) {
			string s = "Q";
			vector<string> str;
			str.push_back(s);
			result.push_back(str);
			return result;
		}

		vector<bool> listy(n - 1, false);
		vector<bool> list1(2 * n - 1, false);
		vector<bool> list2(2 * n - 1, false);

		for (int i = 0; i < n; i++) {
			vector<int> c;
			c.push_back(i);
			listy[i] = true;
			list1[i] = true;
			list2[0 - i + n - 1] = true;
			generateNQueens(n, 1, c, listy, list1, list2);
			c.pop_back();
			listy[i] = false;
			list1[i] = false;
			list2[0 - i + n - 1] = false;
		}
		for (int i = 0; i < res.size(); i++) {
			vector<string> str;
			string s;
			for (int k = 0; k < n; k++)
				s.push_back('.');

			for (int j = 0; j < res[i].size(); j++) {
				s[res[i][j]] = 'Q';
				str.push_back(s);
				s[res[i][j]] = '.';
			}
			result.push_back(str);
		}
		return result;
	}
};
//int main() {
//	int n = 4;
//	vector<vector<string>> res = Solution().solveNQueens(n);
//	for (int i = 0; i < res.size(); i++) {
//		for (int j = 0; j < res[i].size(); j++) {
//			for (int k = 0; k < res[i][j].size(); k++) {
//				cout << res[i][j][k] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}