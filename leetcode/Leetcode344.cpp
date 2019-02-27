#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j)
			swap(s[i++], s[j--]);
		return s;
	}
};

//int main() {
//	string str = "A man, a plan, a canal: Panama";
//	string res = Solution().reverseString(str);
//	cout << res << endl;
//
//	return 0;
//}