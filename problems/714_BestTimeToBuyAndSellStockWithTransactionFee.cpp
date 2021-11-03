#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // space optimized dp
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int f0 = -prices[0]; // 持有股票的收益
        int f1 = 0; // 不持有股票的收益
        for (int i = 1; i < n; i++) {
            int newf0 = max(f0, f1 - prices[i]);
            int newf1 = max(f1, f0 + prices[i] - fee);
            f0 = newf0;
            f1 = newf1;
        }

        return max(f0, f1);
    }

    int maxProfit_greedy(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        
        return profit;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int fee = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> prices;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    Solution solution;
    cout << solution.maxProfit(prices, fee) << endl;

    //system("pause");
    return 0;
}
