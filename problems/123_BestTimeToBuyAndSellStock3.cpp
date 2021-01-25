#include <iostream>
#include <vector>

using namespace std;

class Solution123 {
public:
	int max (const int a, const int b) {
		return a > b ? a : b;
	}

	int min(const int a, const int b) {
		return a > b ? b : a;
	}

	// Time: O(k^2), Space: O(k)
    int maxProfit_bidirect_dp(vector<int>& prices) {
        int n = prices.size();
		if (n == 0) return 0;
		
        vector<int> left_profits(n, 0), right_profits(n, 0);

		int left_min = prices[0];
		int right_max = prices[n - 1];
    	for (int l = 1; l < n; l++) {
    		// left profit
			left_profits[l] = max(left_profits[l - 1], prices[l] - left_min);
			left_min = min(prices[l], left_min);

    		// right profit
			int r = n - l - 1;
			right_profits[r] = max(right_profits[r + 1], right_max - prices[r]);
			right_max = max(prices[r], right_max);
    	}
		
		int max = 0;
		for (int i = 0; i < n; i++) {
			int profit = left_profits[i] + right_profits[i];
			max = profit > max ? profit : max;
		}

		return max;
    }

	// Time: O(k), Space: O(1)
	int maxProfit(vector<int>& prices) {
		int t1Cost = INT_MAX,
			t2Cost = INT_MAX;
		int t1Profit = 0,
			t2Profit = 0;

		for (int price : prices) {
			// the maximum profit if only one transaction is allowed
			t1Cost = min(t1Cost, price); // 全局最低的price
			t1Profit = max(t1Profit, price - t1Cost); // 第一次交易的最大利润，不一定对应当前t1Cost
			// re-invest the gained profit in the second transaction
			t2Cost = min(t2Cost, price - t1Profit); // key!!!!!!!!!!!!!!!
			t2Profit = max(t2Profit, price - t2Cost);
		}

		return t2Profit;
	}
};

int main123() {
	int n;
	vector<int> prices;

	cout << "please input n: ";
	cin >> n;
	cout << "please input n prices: " << endl;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		prices.push_back(x);
	}

	Solution123 solution;
	cout << "max profit: " << solution.maxProfit_bidirect_dp(prices) << endl;

	system("pause");
	
	return 0;
}