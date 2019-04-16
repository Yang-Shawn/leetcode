#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int res = 0;
	void generateNQueens(int n, int x, vector<bool>& listy, vector<bool>& list1, vector<bool>& list2) {
		if (x == n) {
			res++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!listy[i] && !list1[x + i] && !list2[x - i + n - 1]) {
				listy[i] = true;
				list1[x + i] = true;
				list2[x - i + n - 1] = true;
				generateNQueens(n, x + 1, listy, list1, list2);
				listy[i] = false;
				list1[x + i] = false;
				list2[x - i + n - 1] = false;
			}
		}
		return;
	}
public:
	int totalNQueens(int n) {
		if (n <= 0)
			return 0;
		if (n == 1) {
			return 1;
		}

		vector<bool> listy(n - 1, false);
		vector<bool> list1(2 * n - 1, false);
		vector<bool> list2(2 * n - 1, false);

		for (int i = 0; i < n; i++) {
			listy[i] = true;
			list1[i] = true;
			list2[0 - i + n - 1] = true;
			generateNQueens(n, 1, listy, list1, list2);
			listy[i] = false;
			list1[i] = false;
			list2[0 - i + n - 1] = false;
		}
		return res;
	}
};
//int main() {
//	int n = 4;
//	int res = Solution().totalNQueens(n);
//	cout << res << endl;
//	return 0;
//}