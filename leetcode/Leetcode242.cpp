#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		map<char, int> record1, record2;
		for (int i = 0; i < s.size(); i++)
			record1[s[i]]++;
		for (int i = 0; i < t.size(); i++)
			record1[t[i]]--;
		for (int i = 0; i < s.size(); i++) {
			if (record1[s[i]] != 0)
				return false;
		}
		return true;

	}
};

//int main() {
//	string str1 = "abbbg";
//	string str2 = "bbabg";
//	bool res = Solution().isAnagram(str1, str2);
//	cout << res << endl;
//	return 0;
//}