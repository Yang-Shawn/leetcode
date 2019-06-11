#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		map<char, char> record;
		for (int i = 0; i < s.size(); i++) {
			if (record.find(s[i]) == record.end())
				record.insert(make_pair(s[i], t[i]));
			else if (record[s[i]] != t[i])
				return false;
		}
		map<char, char> record1;
		for (int i = 0; i < t.size(); i++) {
			if (record1.find(t[i]) == record1.end())
				record1.insert(make_pair(t[i], s[i]));
			else if (record1[t[i]] != s[i])
				return false;
		}
		return true;
	}
};