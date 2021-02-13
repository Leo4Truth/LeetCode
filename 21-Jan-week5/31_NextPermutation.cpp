#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution31 {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 1;
		// find the first increasing neighbor that nums[i - 1] < nums[i]
		// <= because there will be equal elements
		for (i = n - 1; i > 0 && nums[i] <= nums[i - 1]; i--);
		// if their is not increasing neighbor
		if (i == 0) {
			// obviously, the next permutation is the completerly increasing order
			reverse(nums, i, n - 1);
			return;
		}
		// obviously, nums[i...n-1] is a successive decreasing order
		// and we wanna find j that satisfies both nums[j] > nums[i - 1] and nums[j + 1] <= nums[i - 1]
		// swap nums[i - 1] and nums[j] nums them and reverse nums[i...n-1]
		int j = i;
		// > because we must find nums[j] strictly larger than nums[i - 1] to find the next perm
		for (j = i; j < n - 1 && nums[j + 1] > nums[i - 1]; j++);
		int tmp = nums[i - 1];
		nums[i - 1] = nums[j];
		nums[j] = tmp;
		reverse(nums, i, n - 1);
		return;
	}

	void reverse(vector<int>& nums, int a, int b) {
		if (a == b) return;
		if (a >= nums.size() || b >= nums.size() || a < 0 || b < 0) return;
		for (int i = a; i <= (a + b) / 2; i++) {
			int j = a + b - i;
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
	}
};

int main31() {
	Solution31 solution;
	vector<int> nums;
	int n;
	cout << "input the size of the array: " << endl;
	cin >> n;
	cout << "input " << n << " elements of the array: " << endl;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	solution.nextPermutation(nums);
	cout << "the next permutation is: " << endl;
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	int x;
	cin >> x;
	return 0;
}