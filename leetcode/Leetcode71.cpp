#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

class Solution {
private:
	//×Ö·û´®·Ö¸îº¯Êý
	std::vector<std::string> split1(std::string str, std::string pattern)
	{
		std::string::size_type pos;
		std::vector<std::string> result;
		str += pattern;//À©Õ¹×Ö·û´®ÒÔ·½±ã²Ù×÷
		int size = str.size();

		for (int i = 0; i < size; i++)
		{
			pos = str.find(pattern, i);
			if (pos < size)
			{
				std::string s = str.substr(i, pos - i);
				result.push_back(s);
				i = pos + pattern.size() - 1;
			}
		}
		return result;
	}
	vector<string> split(string str, string avg) {
		str = str + avg;
		vector<string> vec;
		string::size_type pos = 0, start = 0;

		while (pos < str.size()) {
			pos = str.find(avg, start);
			if (pos < str.size()) {
				string subs = str.substr(start, pos - start);
				vec.push_back(subs);
			}
			start = pos + avg.size();
		}
		return vec;
	}
public:
	string simplifyPath(string path) {
		vector<string> vec = split(path, "/");
		stack<string> sta;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] != "" && vec[i] != ".") {
				if (vec[i] == "..") {
					if (!sta.empty())
						sta.pop();
				}
				else
					sta.push(vec[i]);
			}
		}
		vector<string> vec2;
		while (!sta.empty()) {
			vec2.push_back(sta.top());
			sta.pop();
		}

		string res = "/";
		for (int i = vec2.size() - 1; i > 0; i--)
			res = res + vec2[i] + "/";
		if (vec2.size() != 0)
			res = res + vec2[0];
		return res;
	}
};

//int main() {
//	string s = "/a//b////c/d//././/..";
//	string res = Solution().simplifyPath(s);
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i];
//	return 0;
//}