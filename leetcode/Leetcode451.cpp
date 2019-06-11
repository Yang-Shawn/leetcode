#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
typedef pair<char, int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second > rhs.second;
}

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second > rhs.second;
	}
};
public:
	string frequencySort(string s) {
		map<char, int> record;
		for (int i = 0; i < s.size(); i++) {
			if (record.find(s[i]) == record.end())
				record.insert(make_pair(s[i], 1));
			else
				record[s[i]]++;
		}
		//把map中元素转存到vector中 
		vector<PAIR> vec(record.begin(), record.end());
		sort(vec.begin(), vec.end(), CmpByValue());
		string res;
		for (int i = 0; i < vec.size(); i++) 
			for (int j = 0; j < vec[i].second; j++)
                res.push_back(vec[i].first);
		
		return res;
	}
};