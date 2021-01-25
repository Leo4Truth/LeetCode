#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution122 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int max = 0;
		for (int i = 1; i < n; i++) {
			if (prices[i] > prices[i - 1])
				max += prices[i] - prices[i - 1];
		}
		return max;
	}
};