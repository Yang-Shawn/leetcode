#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// record <��ֵ��Ƶ��>
		map<int, int> record;
		for (int i = 0; i < nums.size(); i++) 
			record[nums[i]]++;

		// pq <Ƶ�ʣ���ֵ>
		priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		for (map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++) {
			if (pq.size() == k) {
				if (iter->second > pq.top().first) {
					pq.pop();
					pq.push(make_pair(iter->second, iter->first));
				}
			}
			else
				pq.push(make_pair(iter->second, iter->first));
		}
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};