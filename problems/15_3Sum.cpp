#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution15 {
public:
	// Exceed time-limit
    vector<vector<int>> threeSumFailed(vector<int>& nums) {
        vector<vector<int>> answers;
        int n = nums.size();
        if (n < 3) return answers;
        
        int first, second, third;

        for (first = 0; first < n - 2; first++) {
            for (second = first + 1; second < n - 1; second++) {
                int found = false, target;
                for (third = second + 1; third < n; third++) {
                    if (nums[first] + nums[second] + nums[third] == 0) {
                        vector<int> answer;
                        answer.push_back(nums[first]);
                        answer.push_back(nums[second]);
                        answer.push_back(nums[third]);
                        bool dup = false;
                        for (int i = 0; i < answers.size(); i++) {
                            if ((answers[i][0] == nums[first] && answers[i][1] == nums[second] && answers[i][2] == nums[third]) ||
                                (answers[i][0] == nums[first] && answers[i][2] == nums[second] && answers[i][1] == nums[third]) ||
                                (answers[i][1] == nums[first] && answers[i][0] == nums[second] && answers[i][2] == nums[third]) ||
                                (answers[i][1] == nums[first] && answers[i][2] == nums[second] && answers[i][0] == nums[third]) ||
                                (answers[i][2] == nums[first] && answers[i][0] == nums[second] && answers[i][1] == nums[third]) ||
                                (answers[i][2] == nums[first] && answers[i][1] == nums[second] && answers[i][0] == nums[third])) {
                                dup = true;
                                break;
                            }
                        }
                        if (!dup) answers.push_back(answer);
                    }
                }
            }
        }

        return answers;
    }

	// O(N^2)
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> results;
		if (nums.size() < 3) return results;
		sort(nums.begin(), nums.end()); // sort
		for (int i = 0; i < nums.size() - 2; i++) {
			if (nums[i] > 0) break; // speed up, because the array was sorted, if the first num is bigger than 0, then the sum must exceed 0 
			if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate numbers for the first number
			int target = 0 - nums[i];
			// two pointers
			for (int j = i + 1, k = nums.size() - 1; j < k;) {
				if (nums[j] + nums[k] == target) {
					vector<int> res;
					res.push_back(nums[i]);
					res.push_back(nums[j]);
					res.push_back(nums[k]);
					results.push_back(res);
					// skip duplicate numbers for the second and the third number
					while (j < k && nums[j] == nums[j + 1]) j++;
					while (j < k && nums[k] == nums[k - 1]) k--;
					j++;
					k--;
				}
				else if (nums[j] + nums[k] < target) j++;
				else k--;
			}
		}
		return results;
	}
};

int main15() {
    Solution15 solution;

    // TODO: test
    vector<int> nums;
    int n, x;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    vector<vector<int>> res = solution.threeSum(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << endl;
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}