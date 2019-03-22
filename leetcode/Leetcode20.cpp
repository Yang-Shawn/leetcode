#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack <char> sta;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				sta.push(s[i]);
			else {
				if (sta.size() == 0)
					return false;
				char top_sta = sta.top();
				sta.pop();
				char match;
				if (s[i] == ')')
					match = '(';
				else if (s[i] == '}')
					match = '{';
				else
					match = '[';

				if (top_sta != match)
					return false;
			}
		}
		if (sta.size() != 0)
			return false;
		return true;
	}
};

//int main() {
//	string s = "{[((())]}";
//	bool res = Solution().isValid(s);
//	cout << res << endl;
//	return 0;
//}