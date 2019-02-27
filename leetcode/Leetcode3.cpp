#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int freq[256] = { 0 };
		int res = 0;
		int l = 0, r = -1;
		while (l < s.size()) {
			if (freq[s[r + 1]] == 0 && r + 1 < s.size())
				freq[s[++r]]++;
			else
				freq[s[l++]]--;
			res = max(res, r - l + 1);
		}
		return res;
	}
};

//int main() {
//	string s = "pwwkew";
//	int res = Solution().lengthOfLongestSubstring(s);
//	cout << res << endl;
//	return 0;
//}