#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			while ( isalnum(s[i]) == 0 && i < j ) {
				i++;
			}
			while ( isalnum(s[j]) == 0 && i < j) {
				j--;
			}
			if (toupper(s[i++]) != toupper(s[j--]))
				return false;
		}
		return true;
	}
};

//int main() {
//	string str = "0P";
//	bool res = Solution().isPalindrome(str);
//	bool re = true;
//	cout << res <<endl;
//	
//	return 0;
//}