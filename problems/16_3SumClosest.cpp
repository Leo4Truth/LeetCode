#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution16 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int closest;
		if (nums.size() < 3) return -1;
		sort(nums.begin(), nums.end()); // sort
		closest = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate numbers for the first number
			// two pointers
			for (int j = i + 1, k = nums.size() - 1; j < k;) {
				int sum = nums[i] + nums[j] + nums[k];
				int distance = abs(sum - target);

				//cout << "i, j, k = " << i << ", " << j << ", " << k << endl;
				//cout << "sum = " << sum << ", distance = " << distance << endl;

				if (distance == 0) return target;
				if (distance <= abs(closest - target)) closest = sum;

				if (sum < target) {
					while (j < k && nums[j] == nums[j + 1]) j++; // skip duplicate
					j++;
				}
				else {
					while (j < k && nums[k] == nums[k - 1]) k--; // skip duplicate
					k--;
				}
			}
		}
		return closest;
	}

	int abs(int x) {
		return x > 0 ? x : -x;
	}
};

int main16() {
	Solution16 solution;
	vector<int> nums({ 0, 2, 1, -3 });
	int target = 1;
	cout << solution.threeSumClosest(nums, target) << endl;
	system("pause");
	return 0;
}