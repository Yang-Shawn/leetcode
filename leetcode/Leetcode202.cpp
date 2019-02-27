#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		set<int> record;
		while (n != 1 && record.find(n) == record.end()) {
			record.insert(n);
			int num = 0;
			while (n != 0) {
				num = num + pow(n % 10, 2);
				n = n / 10;
			}
			n = num;
		}
		if (n == 1)
			return true;
		else
			return false;
	}
};

//int main() {
//	int num = 20;
//	bool res = Solution().isHappy(num);
//	cout << res << endl;
//	return 0;
//}