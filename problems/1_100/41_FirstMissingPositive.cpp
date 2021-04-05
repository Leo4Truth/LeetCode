#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution41 {
public:
	int firstMissingPositive_failed(vector<int>& nums) {
		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
		}
		//cout << "max = " << max << endl;
		bool *exist = new bool[max + 1];
		memset(exist, false, max + 1);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) exist[nums[i]] = true;
		}
		/*
		for (int i = 0; i < max + 1; i++)
			cout << i << ": " << exist[i] << endl;
		*/
		for (int i = 1; i < max + 1; i++) {
			if (!exist[i]) return i;
		}
		return max + 1;
	}

	int firstMissingPositive_hash(vector<int>& nums) {
		int firstMissing = 1;
		unordered_map<int, bool> exist;
		for (int i = 0; i < nums.size(); i++) {
			exist[nums[i]] = true;
			if (nums[i] == firstMissing) {
				while (exist[firstMissing]) {
					firstMissing++;
				}
			}
		}
		return firstMissing;
	}

	int firstMissingPositive(vector<int>& nums) {
		int m = nums.size();
		if (m == 0) return 1;
		if (m == 1) return nums[0] == 1 ? 2 : 1;
		bool is_m = false;
		for (int i = 0; i < m; i++) {
			if (nums[i] < 0 || nums[i] > m) nums[i] = 0;
			if (nums[i] == m) {
				is_m = true;
				nums[i] = 0;
			}
		}
		for (int i = 0; i < m; i++)
			nums[nums[i] % m] += m;
		for (int i = 1; i < m; i++) // start from 1 !!!
			if (nums[i] / m == 0) return i;
		return is_m ? m + 1 : m;
	}
};

int main41()
{
	Solution41 solution;
	int n, x;
	vector<int> nums;
	int target;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}
	cout << solution.firstMissingPositive(nums) << endl;
	system("pause");
	return 0;
}