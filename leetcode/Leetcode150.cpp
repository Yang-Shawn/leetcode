#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty())
			return 0;
		stack<string> sta;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == "+" || tokens[i] == "-" ||
				tokens[i] == "*" || tokens[i] == "/") {
				int b = stoi(sta.top());
				sta.pop();

				int a = stoi(sta.top());
				sta.pop();

				if (tokens[i] == "+")
					sta.push(to_string(a + b));
				else if (tokens[i] == "-")
					sta.push(to_string(a - b));
				else if (tokens[i] == "*")
					sta.push(to_string(a * b));
				else
					sta.push(to_string(a / b));
			}
			else
				sta.push(tokens[i]);
		}
		int res = stoi(sta.top());
		sta.pop();
		return res;
	}
};