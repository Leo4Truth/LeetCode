#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual int minMoves2(vector<int>& nums) = 0;
};

/**
 * @brief Sort
 * Time Complexity: O(NlogN)
 * Space Complexity: O(N)
 */
class Solution_Sort : public Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ret = 0, x = nums[n / 2];
        for (int i = 0; i < n; i++) {
            ret += abs(nums[i] - x);
        }
        return ret;
    }
};

/**
 * @brief quick select
 * Time Complexity: O(N)
 * SPace Complexity: O(logN)
 */
class Solution_QuickSelect : public Solution {
public:
    int minMoves2(vector<int>& nums) {
        srand(time(0));
        int n = nums.size(), x = quickSelect(nums, 0, n - 1, n / 2), ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += abs(nums[i] - x);
        }
        return ret;
    }

private:
    int quickSelect(vector<int>& nums, int left, int right, int index) {
        int q = randomPartition(nums, left, right);
        if (q == index) {
            return nums[q];
        } else {
            return q < index ? quickSelect(nums, q + 1, right, index) : quickSelect(nums, left, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& nums, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[right]);
        return partition(nums, left, right);
    }

    inline int partition(vector<int>& nums, int left, int right) {
        int x = nums[right], i = left - 1;
        for (int j = left; j < right; ++j) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution *solution = nullptr;

    solution = new Solution_Sort();
    cout << "Sort        : " << solution->minMoves2(nums) << endl;
    
    solution = new Solution_QuickSelect();
    cout << "Quick Select: " << solution->minMoves2(nums) << endl;

    return 0;
}
