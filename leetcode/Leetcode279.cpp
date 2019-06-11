#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		vector<int> vec;
		for (int i = 0; i < n + 1; i++)
			vec.push_back(i);
		for (int i = 1; i * i < n + 1; i++) {
			vec[i * i] = 1;
		}
		for (int i = 1; i < n + 1; i++) 
			for (int j = 1; j * j <= i && i + j * j < n + 1; j++) 
				vec[i + j * j] = min(vec[i] + 1, vec[i + j * j]);

		return vec[n];
	}
};