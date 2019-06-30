#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<string> res;
	const string letter[10] =
	{
		" ",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};
	void generateLC(string digits, int start, string &c) {
		if (c.size() == digits.size()) {
			res.push_back(c);
			return;
		}
		for (int i = start; i < digits.size(); i++) {
			int cur = digits[i] - '0';
			for (int j = 0; j < letter[cur].size(); j++) {
				c.push_back(letter[cur][j]);
				generateLC(digits, i + 1, c);
				c.pop_back();
			}
		}
		return;
	}
public:
	vector<string> letterCombinations(string digits) {
		res.clear();
		if (digits.empty())
			return res;
		string c;
		generateLC(digits, 0, c);
		return res;
	}
};