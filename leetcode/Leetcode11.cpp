#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxArea = 0;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int newArea = min(height[i], height[j]) * (j - i);
			maxArea = max(maxArea, newArea);
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
		return maxArea;
	}
};

//int main() {
//	int num[] = { 1,8,6,2,5,4,8,3,7 };
//	vector<int> vec(num, num + sizeof(num) / sizeof(int));
//	int res = Solution().maxArea(vec);
//	cout << res << endl;
//	return 0;
//}