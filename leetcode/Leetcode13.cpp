#include <iostream>
#include <string>
using namespace std;
int romanToInt(string s) {
	int i, j;
	int res = 0;
	int len = s.length();
	char* c = (char*)s.data();
	for (i = len - 1; i > 0; i--) {
		if (c[i] == 'I') {
			res = res + 1;
		}
		else if (c[i] == 'V') {
			j = i - 1;
			if (c[j] == 'I') {
				res = res + 4;
				i = i - 1;
			}
			else {
				res = res + 5;
			}
		}
		else if (c[i] == 'X') {
			j = i - 1;
			if (c[j] == 'I') {
				res = res + 9;
				i = i - 1;
			}
			else {
				res = res + 10;
			}
		}
		else if (c[i] == 'L') {
			j = i - 1;
			if (c[j] == 'X') {
				res = res + 40;
				i = i - 1;
			}
			else {
				res = res + 50;
			}
		}
		else if (c[i] == 'C') {
			j = i - 1;
			if (c[j] == 'X') {
				res = res + 90;
				i = i - 1;
			}
			else {
				res = res + 100;
			}
		}
		else if (c[i] == 'D') {
			j = i - 1;
			if (c[j] == 'C') {
				res = res + 400;
				i = i - 1;
			}
			else {
				res = res + 500;
			}
		}
		else if (c[i] == 'M') {
			j = i - 1;
			if (c[j] == 'C') {
				res = res + 900;
				i = i - 1;
			}
			else {
				res = res + 1000;
			}
		}
	}
	if (i == 0) {
		if (c[0] == 'I') {
			res = res + 1;
		}
		else if (c[0] == 'V') {
			res = res + 5;
		}
		else if (c[0] == 'X') {
			res = res + 10;
		}
		else if (c[0] == 'L') {
			res = res + 50;
		}
		else if (c[0] == 'C') {
			res = res + 100;
		}
		else if (c[0] == 'D') {
			res = res + 500;
		}
		else if (c[0] == 'M') {
			res = res + 1000;
		}
	}

	return res;
}
//int main() {
//	string s;
//	cin >> s;
//	int res = romanToInt(s);
//	cout << res;
//	return 0;
//}