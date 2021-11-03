#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	// sort
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        int maxLen = 0;
        int len = 1;
    	for (int i = 0; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) len++;
            else if (nums[i] != nums[i - 1]) len = 1;
            maxLen = len > maxLen ? len : maxLen;
    	}

        return maxLen;
    }

    int longestConsecutive_2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> set;
        for (auto num : nums) set.insert(num);

        int maxLen = 0;
    	for (auto num : set) {
    		// 只有num是连续数列开头是才进入计数
    		if (!set.count(num-1)) {
                int currentNum = num;
                int len = 1;
    			while (set.count(currentNum + 1)) {
                    currentNum += 1;
                    len += 1;
    			}
                maxLen = len > maxLen ? len : maxLen;
    		}
    	}

        return maxLen;
    }
};

