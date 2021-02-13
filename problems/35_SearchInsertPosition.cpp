#include <iostream>
#include <vector>

using namespace std;

class Solution35 {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		if (!nums.empty() && nums.at(0) >= target) return 0;
		for (auto i = 1; i < nums.size(); i++) {
			if (nums.at(i - 1) < target && nums.at(i) >= target) return i;
		}
		return nums.size();
	}
};

int main35() {
	Solution35 solution;
	vector<int> nums;
	int target;

	int x;
	for (int i = 0; ; i++) {
		cin >> x;
		if (x > 0) nums.push_back(x);
		else break;
	}
	cin >> target;

	cout << solution.searchInsert(nums, target) << endl;;

	system("pause");

	return 0;
}