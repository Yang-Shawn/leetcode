#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> record;
		for (int i = 0; i < nums.size(); i++) {
			if (record.find(nums[i]) != record.end())
				return true;
			else
				record.insert(nums[i]);
		}
		return false;
	}
};