#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size() < t.size())
			return "";
		int freq[256] = { 0 };
		int tar[256] = { 0 };
		for (int i = 0; i < t.size(); i++) {
			tar[t[i]] ++;
		}
		int l = 0, r = -1; // [l, r]为一个包含t的窗口
		int len = s.size() + 1;
		int res[2] = { 0, s.size() };
		while (l < s.size()) {
			bool judge = true;
			for (int i = 'A'; i < 'z'; i++) {
				if (tar[t[i]] != 0 && freq[t[i]] < tar[t[i]]) {
					judge = false;
					break;
				}
			}
		
			if (r + 1 < s.size() && !judge)
				freq[s[++r]]++;
			else
				freq[s[l++]]--;

			judge = true;
			for (int i = 'A'; i < 'z'; i++) {
				if (tar[t[i]] != 0 && freq[t[i]] < tar[t[i]]) {
					judge = false;
					break;
				}
			}
			if (judge && r - l + 1 < len) {
				len = r - l + 1;
				res[0] = l;
				res[1] = r;
			}
		}

		if (len == s.size() + 1)
			return "";
		
		string result;
		for (int i = res[0]; i <= res[1]; i++) {
			result.push_back(s[i]);
		}
		return result;
	}
};