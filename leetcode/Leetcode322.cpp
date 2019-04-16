#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {	
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> res(amount + 1, -1);
		if (coins.size() <= 0 || amount < 0)
			return -1;
		if (amount == 0)
			return 0;
		sort(coins.begin(), coins.end());
		for (int i = 0; i < coins.size() && coins[i] <= amount; i++) {
			res[coins[i]] = 1;
		}

		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				for (int k = 1; k * coins[j] <= i; k++) {
					if (res[i - k * coins[j]] != -1) {
						if (res[i] == -1)
							res[i] = res[i - k * coins[j]] + k;
						else {
							res[i] = min(res[i], res[i - k * coins[j]] + k);
							break;
						}
					}
				}
			}
		}
		return res[amount];
	}
};