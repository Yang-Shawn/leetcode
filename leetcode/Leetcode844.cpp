#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int i = S.size() - 1, j = T.size() - 1;
		vector<char> vecS;
		int num1 = 0;
		while (i >= 0) {
			while (S[i] == '#' && i >= 0) {
				num1++;
				i--;
			}
			while (i >= 0 && S[i] != '#' && num1 != 0) {
				i--;
				num1--;
			}
			while (i >= 0 && S[i] != '#') {
				vecS.push_back(S[i]);
				i--;
			}
		}
		vector<char> vecT;
		int num2 = 0;
		while (j >= 0) {
			while (T[j] == '#' && j >= 0) {
				num2++;
				j--;
			}
			while (j >= 0 && T[j] != '#' && num2 != 0) {
				j--;
				num2--;
			}
			while ( j >= 0 && T[j] != '#' ) {
				vecT.push_back(T[j]);
				j--;
			}
		}
		if (vecS.size() != vecT.size())
			return false;
		for (int i = 0; i < vecS.size(); i++) {
			if (vecS[i] != vecT[i])
				return false;
		}
		return true;
	}
};

//int main() {
//	string s1 = "bxj##tw";
//	string s2 = "bxo#j##tw";
//	bool res = Solution().backspaceCompare(s1, s2);
//	cout << res << endl;
//	return 0;
//}