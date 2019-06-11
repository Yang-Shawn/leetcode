#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	int m, n;
	bool inMatrix(int x, int y) {
		if (x >= 0 && x < m && y >= 0 && y < n)
			return true;
		return false;
	}
	bool isPacific(int x, int y) {
		if (x < 0 || y < 0)
			return true;
		return false;
	}
	bool isAtlantic(int x, int y) {
		if (x >= m || y >= n)
			return true;
		return false;
	}

public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		res.clear();
		m = matrix.size();
		if (m == 0)
			return res;
		n = matrix[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

			}
		}
	}
};