#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> move = { {0,1},{1,0},{0,-1},{-1,0} };
	
	bool inside(vector<vector<char>>& board, int x, int y) {
		return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
	}
	bool generateExist(vector<vector<char>>& board, string word, int x, int y, int num, vector<vector<bool>>& visit) {
		if (num == word.size())
			return true;
		for (int i = 0; i < 4; i++) {
			int newX = x + move[i][0];
			int newY = y + move[i][1];
			//cout << inside(board, newX, newY) << endl;
			if (inside(board, newX, newY) && !visit[newX][newY] && board[newX][newY] == word[num]) {
				//cout<<"第" << num << "个匹配位置(x,y): " << newX << "," << newY << endl;
				visit[newX][newY] = true;
				if (generateExist(board, word, newX, newY, num + 1, visit))
					return true;
				visit[newX][newY] = false;
			}
		}
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || word.empty())
			return false;
		
		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					visit[i][j] = true;
					//cout << "第0个匹配位置(x,y): " << i << "," << j << endl;
					if (generateExist(board, word, i, j, 1, visit))
						return true;
					visit[i][j] = false;
				}
			}
		}
		return false;
	}
};

//int main() {
//	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
//	string word = "ABCB";
//	bool res = Solution().exist(board, word);
//	cout << res << endl;
//	return 0;
//}