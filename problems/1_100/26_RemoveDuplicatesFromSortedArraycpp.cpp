#include <iostream>
#include <vector>

using namespace std;

class Solution26 {
public:
	int removeDuplicates(vector<int>& nums) {
		int length = 0;

		if (nums.empty()) return 0;

		int x = nums.at(0);
		for (auto i = 1; i < nums.size(); i++) {
			if (x != nums.at(i)) {
				x = nums.at(i);
				nums.at(++length) = x;
			}
		}
		nums.erase(nums.begin() + length + 1, nums.end());

		return length + 1;
	}
};

int main26() {
	vector<int> nums;
	int x;
	cin >> x;
	while (x > 0) {
		nums.push_back(x);
		cin >> x;
	}
	cout << "input done" << endl;

	Solution26 solution;
	solution.removeDuplicates(nums);
	for (auto i = 0; i < nums.size(); i++) {
		if (i != 0) cout << ", ";
		cout << nums.at(i);
	}

	system("pause");

	return 0;
}