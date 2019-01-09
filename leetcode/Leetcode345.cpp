#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			while (toupper(s[i]) != 'A' && toupper(s[i]) != 'E' && toupper(s[i]) != 'I' && 
				toupper(s[i]) != 'O' && toupper(s[i]) != 'U' && i < j)
				i++;
			while (toupper(s[j]) != 'A' && toupper(s[j]) != 'E' && toupper(s[j]) != 'I' &&
				toupper(s[j]) != 'O' && toupper(s[j]) != 'U' && i < j)
				j--;
			swap(s[i++], s[j--]);
		}
		return s;
	}
};

//int main() {
//	string str = "Addddeddd";
//	string res = Solution().reverseVowels(str);
//	cout << res << endl;
//
//	return 0;
//}