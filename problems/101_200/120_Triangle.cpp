#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// optimized dp
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n == 0) return 0;
		
		vector<int> dp(triangle[n - 1]);

		for (int lvl = n - 1; lvl > 0; lvl--) {
			for (int i = 0; i < lvl; i++) {
				if (dp[i] <= dp[i + 1]) dp[i] = dp[i] + triangle[lvl - 1][i];
				else dp[i] = dp[i + 1] + triangle[lvl - 1][i];
			}
		}

		return dp[0];
	}
};