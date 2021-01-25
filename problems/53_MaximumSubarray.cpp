#include <iostream>
#include <vector>

using namespace std;

class Solution53 {
public:
	/*
	 * Dynamic Planning
	 * O(n) Time Complexity
	 */
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;	// deal with empty input

		// optimized initialization can improve shorten the running time
		int maxSum = nums.at(0);
		int maxTmp = nums.at(0);
		for (auto i = 1; i < nums.size(); i++) {
			if (maxTmp <= 0) maxTmp = nums.at(i);
			else maxTmp += nums.at(i);

			if (maxTmp > maxSum) maxSum = maxTmp;
		}
		return maxSum;
	}
};

int main53() {
	vector<int> nums;
	int x;
	for (;;) {
		cin >> x;
		if (x > 0) nums.push_back(x);
		else break;
	}
	Solution53 solution;
	cout << solution.maxSubArray(nums);
	system("pause");
	return 0;
}