#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution121 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0) return 0;
		int lowest = prices[0];
		int highest = prices[0];
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (prices[i] < lowest) {
				lowest = prices[i];
				highest = prices[i];
			}
			if (prices[i] > highest) {
				highest = prices[i];
				int profit = highest - lowest;
				if (profit > max) {
					max = profit;
				}
			}
		}
		return max;
	}
};