#include <iostream>
#include <vector>
using namespace std;

	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		else {
			int pre = nums[0];
			int k = 1;
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i] != pre) {
					pre = nums[i];
					if (i != k) {
						nums[k++] = nums[i];
					}
					else {
						k++;
					}
				}
			}
			return k;
		}
	}
	/*int main() {
		int num[] = { 0,0,1,1,2,2,3,5,6,8,8,9 };
		vector<int> vec(num, num + sizeof(num) / sizeof(int));
		int res = removeDuplicates(vec);
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
		cout << res;
		return 0;
	}*/