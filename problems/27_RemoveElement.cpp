#include <iostream>
#include <vector>

using namespace std;

class Solution27 {
public:
	/*
	 * Maintain the original order of the remain array
	 */
	/*
	int removeElement(vector<int>& nums, int val) {
		for (auto i = 0; i < nums.size(); i++) {
			if (nums.at(i) == val) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}
		return nums.size();
	}
	*/

	/*
	 * More quickly solution, no guarantee on order
	 */
	int removeElement(vector<int>& nums, int val) {
		int len = 0;
		for (auto i = 0; i < nums.size(); i++) {
			if (nums.at(i) != val) {
				nums.at(len) = nums.at(i);
				len++;
			}
		}
		return len;
	}
};

int main27() {
	vector<int> nums;
	int x;
	for (;;) {
		cin >> x;
		if (x > 0) nums.push_back(x);
		else break;
	}
	Solution27 solution;
	int val;
	cin >> val;
	solution.removeElement(nums, val);
	for (auto i = 0; i < nums.size(); i++) {
		if (i != 0) cout << ", ";
		cout << nums.at(i);
	}
	cout << endl;
	system("pause");
	return 0;
}