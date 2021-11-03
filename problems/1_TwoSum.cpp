#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
	// brute force
	// time complexity O(N^2)
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int size = nums.size();
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (nums.at(i) + nums.at(j) == target) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
	
	// use unordered_map
	// time complexity O(N)
	vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> umap;
		int size = nums.size();

		for (int i = 0; i < size; i++) {
			int numToFind = target - nums.at(i);
			if (umap.find(numToFind) != umap.end()) {
				result.push_back(umap[numToFind]);
				result.push_back(i);
				return result;
			}
			umap[nums[i]] = i;
		}
		return result;
	}
};

int main1()
{
	Solution1 solution;
	int x;
	vector<int> nums;
	int target;
	cin >> x;
	while (x > 0) {
		nums.push_back(x);
		cin >> x;
	}
	cin >> target;
	vector<int> result = solution.twoSum2(nums, target);
	cout << "[" << result.at(0) << ", " << result.at(1) << "]" << endl;
	system("pause");
	return 0;
}