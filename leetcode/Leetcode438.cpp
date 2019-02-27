#include <iostream>
#include <vector>
#include <string>
using namespace std;

// unsolved

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		if (s.size() < p.size()) {
			vector<int> vec;
			return vec;
		}
		int freq[256] = { 0 };
		for (int i = 0; i < p.size(); i++)
			freq[p[i]] ++;
		int L = 0, r = -1;
		int num = 0;
		int res[20101] = { 0 };
		for (int i = 0; i < s.size() - p.size() + 1; i++) {
			for (int j = i; j < i + p.size(); j++) {
				if (freq[s[j]] > 0)
					freq[s[j]]--;
			}
			bool judge = true;
			for (int j = 0; j < p.size(); j++) {
				if (freq[p[j]] != 0)
					judge = false;
			}
			if (judge == true) {
				res[num] = i;
				num++;
			}
			for (int j = 0; j < p.size(); j++)
				freq[p[j]] = 0;
			for (int j = 0; j < p.size(); j++)
				freq[p[j]] ++;
		}
		vector<int> vec(res, res + num);
		return vec;
	}
};

//int main() {
//	string str = "baa";
//	string sub = "aa";
//	vector<int> res = Solution().findAnagrams(str, sub);
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << " ";
//	return 0;
//}