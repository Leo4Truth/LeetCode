#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;

        if (nums.size() < 4) return results;

		sort(nums.begin(), nums.end());
		/*
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		*/
        for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if (nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				if (nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;

				int m = j + 1, n = nums.size() - 1;

				while (m < n) {
					int sum = nums[i] + nums[j] + nums[m] + nums[n];
					//cout << "\"" << i << j << m << n << "\"" << endl;
					if (sum < target) m++;
					else if (sum > target) n--;
					else {
						//cout << "find!" << endl;
						vector<int> res({ nums[i], nums[j], nums[m], nums[n] });
						results.push_back(res);
						do { m++; } while (nums[m] == nums[m - 1] && m < n);
						do { n--; } while (nums[n] == nums[n + 1] && m < n);
					}
				}
            }
        }

        return results;
    }
};

int main18() {
    Solution18 solution;
    vector<int> nums;
    int n, x, target;
    cout << "input n: ";
    cin >> n;
    cout << "input n numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    cout << "input target: ";
    cin >> target;
    vector<vector<int>> res = solution.fourSum(nums, target);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "  [";
        for (int j = 0; j < 3; j++) {
			cout << res[i][j] << ", ";
        }
        cout << res[i][3] << "]," << endl;
    }
    cout << "]" << endl;

	system("pause");

    return 0;
}
