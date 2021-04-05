#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution90 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		if (n == 0) return res;

		map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			if (cnt.find(nums[i]) == cnt.end()) cnt[nums[i]] = 1;
			else cnt[nums[i]]++;
		}
		/*
		for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
			cout << it->first << ": " << it->second << endl;
		}
		cout << endl;
		*/
		vector<int> current;
		res.push_back(current);
		backtracking(res, nums, cnt, INT_MIN, current);

		return res;
	}

	void backtracking(vector<vector<int>>& res, vector<int>& nums, map<int, int>& cnt, int max, vector<int>& current) {
		for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
			if (it->second > 0) {
				if (it->first < max) continue;
				it->second--;;
				current.push_back(it->first);
				res.push_back(current);
				backtracking(res, nums, cnt, it->first, current);
				current.pop_back();
				it->second++;
			}
		}
	}
};

int main90() {
	Solution90 solution;
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	vector<vector<int>> res = solution.subsetsWithDup(nums);
	cout << "[" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "\t[";
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
			if (j < res[i].size() - 1) cout << ", ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
	
	system("pause");
	return 0;
}