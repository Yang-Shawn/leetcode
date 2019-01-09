#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < target) {
			res = i+1;
		}
		else {
			break;
		}
	}
	return res;
}
//int main() {
//	int tar = 0;
//	int num[] = {1,3,5,6};
//	vector<int> vec(num, num + sizeof(num)/sizeof(int));
//	int res = searchInsert(vec, tar);
//	cout << res;
//	return 0;
//}