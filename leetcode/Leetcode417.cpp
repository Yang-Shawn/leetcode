#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	
	vector<vector<bool>> toPacific;
	vector<vector<bool>> toAtlantic;
	vector<vector<bool>> visited;
	int m, n;
	int move[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };


	bool inMatrix(int x, int y) {
		if (x >= 0 && x < m && y >= 0 && y < n)
			return true;
		return false;
	}

	void generatePacificAtlantic(vector<vector<int>>& matrix, int x, int y) {
		for (int i = 0; i < 4; i++) {
			int newX = x + move[i][0];
			int newY = y + move[i][1];
			if (inMatrix(newX, newY) && matrix[x][y] >= matrix[newX][newY] && toAtlantic[newX][newY] == true){
				toAtlantic[x][y] = true;
			}
			if (inMatrix(newX, newY) && matrix[x][y] >= matrix[newX][newY] && toPacific[newX][newY] == true) {
				toPacific[x][y] = true;
			}
			if (toAtlantic[x][y] == true && toPacific[x][y] == true)
				break;
			if (inMatrix(newX, newY) && matrix[x][y] >= matrix[newX][newY] && visited[newX][newY] == true)
				continue;
			if (inMatrix(newX, newY))
				generatePacificAtlantic(matrix, newX, newY);
		}
		visited[x][y] = true;
	}
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> res;
		m = matrix.size();
		if (m == 0)
			return res;
		n = matrix[0].size();

		visited = vector<vector<bool>>(m, vector<bool>(n, false));
		toPacific = vector<vector<bool>>(m, vector<bool>(n, false));
		toAtlantic = vector<vector<bool>>(m, vector<bool>(n, false));

		for (int i = 0; i < m; i++) 
			toPacific[i][0] = true;
		for (int j = 0; j < n; j++)
			toPacific[0][j] = true;
		for (int i = 0; i < m; i++)
			toAtlantic[i][n - 1] = true;
		for (int j = 0; j < n; j++)
			toAtlantic[m - 1][j] = true;
		
	    generatePacificAtlantic(matrix, 0, 0);

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (toAtlantic[i][j] == true && toPacific[i][j] == true) {
					vector<int> subres;
					subres.push_back(i);
					subres.push_back(j);
					res.push_back(subres);
				}
		return res;
	}
};