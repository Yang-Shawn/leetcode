#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
	 int i, k = 0;
	 for (i = 0; i < nums.size(); i++) {
		 if (nums[i])
			 if (i != k)
				 swap(nums[k++], nums[i]);
			 else
				 k++;
	 }
}
//int main() {
//	 int num[] = { 0,5,6,12,5,0,4,0,2,3,0,0,0,4,0 };
//	 vector<int> vec(num, num + sizeof(num) / sizeof(int));
//	 moveZeroes(vec);
//	 for (int i = 0; i < vec.size(); i++) {
//		 cout << vec[i] << " ";
//	 }
//	 return 0;
//}