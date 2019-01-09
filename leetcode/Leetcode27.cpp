#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	int k = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != val)
			if (i != k)
				swap(nums[k++], nums[i]);
			else
				k++;
	}
	return k;
}
//int main() {
//	int tar = 5;
//	int num[] = { 0,5,6,12,5,0,4,0,2,3,0,0,0,4,0 };
//	vector<int> vec(num, num + sizeof(num) / sizeof(int));
//	int res = removeElement(vec, tar);
//	for (int i = 0; i < vec.size(); i++) {
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	cout << res;
//	return 0;
//}