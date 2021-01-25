#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // key property:
    // In one operation, you can either remove the LEFTMOST or the RIGHTMOST element 
    // from the array nums and subtract its value from x.
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        if (n == 0) {
            if (x == 0) return 0;
            else return -1;
        }

        int total = 0;
        for (int i = 0; i < n; i++) total += nums[i];

        int max_len = -1;
        int current = 0;
        int left = 0, right = 0;
        while (right < n) {
            // sum([left ,..., right]) = total - x
            current += nums[right];
            // if larger, move `left` to left
            while (current > total - x && left <= right) {
                current -= nums[left];
                left += 1;
            }
            // check if equal
            if (current == total - x) {
                max_len = max(max_len, right - left + 1);
            }
            right++;
        }

        // max_len = -1 mens current never is equal to total - x
        return max_len == -1 ? -1 : n - max_len;
    }
};
