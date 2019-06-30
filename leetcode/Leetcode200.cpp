#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int move[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	vector<vector<bool>> visited;
	int m, n;
	bool inNums(int x, int y) {
		if (x >= 0 && x < m && y >= 0 && y < n)
			return true;
		return false;
	}

	void generateNumIslands(vector<vector<char>>& grid, int x, int y) {
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int newX = x + move[i][0];
			int newY = y + move[i][1];
			if (inNums(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1') {
				generateNumIslands(grid, newX, newY);
			}
		}
		return;
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		if (m == 0)
			return 0;
		n = grid[0].size();

		visited = vector<vector<bool>>(m, vector<bool>(n, false));

		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && grid[i][j] == '1') {
					generateNumIslands(grid, i, j);
					res++;
				}
			}
		}
		return res;
	}
};