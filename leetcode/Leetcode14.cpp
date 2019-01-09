#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	string res = "";
	int n = strs.size();
	if (n == 0)
		return res;
	if (n == 1)
		return strs[0];
	for (int i = 0;i < strs[0].size();i++)
		for (int j = 1;j < n;j++)
			if (strs[0][i] != strs[j][i])
				return res;
			else if (j == n - 1)
				res += strs[0][i];
	return res;
}

//int main() {
//	vector<string> strs(10);
//	vector<string>::size_type i = 0;
//	cout << strs.size() << "\n";
//	while (cin >> strs[i]) {
//		i++;
//		if (i >= strs.size())
//		{
//			vector<string> temp(strs.size() * 2);
//			for (vector<string>::size_type j = 0; j < strs.size(); j++)
//			{
//				temp[j] = strs[j];
//			}
//			strs = temp;
//		}
//	}
//	string res = longestCommonPrefix(strs);
//	cout << res;
//	return 0;
//}