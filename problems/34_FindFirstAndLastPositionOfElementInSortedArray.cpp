#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                int i;
                for (i = mid; i >= 0 && nums[i] == target; i--); 
                res.push_back(i + 1);
                for (i = mid; i < nums.size() && nums[i] == target; i++);
                res.push_back(i - 1);
                return res;
            }
            else if (target < nums[mid] && nums[left] <= target) right = mid - 1;
            else left = mid + 1;
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};