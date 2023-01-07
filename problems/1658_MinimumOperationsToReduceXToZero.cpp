#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG

using namespace std;

class Solution {
public:
    virtual int minOperations(vector<int>& nums, int x) = 0;
};

class Solution_official : public Solution {
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

class Solution_2 : public Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        if (n == 0) return x == 0 ? 0 : -1;
        if (n == 1) return nums[0] == x ? 1 : -1;
        
        int total = 0;
        for (int i = 0; i < n; i++) total += nums[i];
        int target = total - x;

        int max_len = -1;
        int current = 0;
        int l = 0, r = 0;
        while (r < n) {
            current += nums[r];
            while (current > target && l <= r) {
                current -= nums[l++];
            }
            if (current == target) {
                max_len = r - l + 1 > max_len ? r - l + 1 : max_len;
#ifdef DEBUG
                cout << l << ", " << r << endl;
#endif // DEBUG
            }
            r++;
        }
        return max_len == -1 ? -1 : n - max_len;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int x= argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution *solution = nullptr;

    solution = new Solution_2();
    cout << solution->minOperations(nums, x) << endl;

    return 0;
}
