#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> vec;
		string resString;
		stringstream input(str);
		while (input >> resString)
			vec.push_back(resString);

		if (pattern.size() != vec.size())
			return false;

		map<char, string> record;
		for (int i = 0; i < pattern.size(); i++) {
			if (record.find(pattern[i]) == record.end()) {
				record.insert(make_pair(pattern[i], vec[i]));
			}
			else {
				if (record[pattern[i]] != vec[i])
					return false;
			}
		}
		return true;
	}
};

//int main() {
//	string str1 = "aba";
//	string str2 = "dog cat cat";
//	bool res = Solution().wordPattern(str1, str2);
//	cout << res << endl;
//	return 0;
//}