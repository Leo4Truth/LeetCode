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
    virtual bool canBeIncreasing(vector<int>& nums) = 0;
};

/**
 * @brief find the non-increasing adjcent index pair
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 从左向右遍历 nums , 寻找非递增相邻下标对 (i - 1, i) 满足 nums[i - 1] <= num[i]
 * 然后检查去除 nums[i - 1] 和 nums[i] 后, nums 是否严格单调递增
 * 遍历数组寻找非递增下标对的最坏时间复杂度为 O(n), 执行一次 check(idx) 函数的时间复杂度为 O(n), 
 * 而我们至多会执行两次 check(idx) 函数
 */
class Solution_official : public Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        // 检查数组 nums 在删去下标为 idx 的元素后是否严格递增
        auto check = [&](const int idx) -> bool{
            for (int i = 1; i < n - 1; ++i){
                int prev = i - 1;
                if (prev >= idx){
                    ++prev;
                }
                int curr = i;
                if (curr >= idx){
                    ++curr;
                }
                if (nums[curr] <= nums[prev]){
                    return false;
                }
            }
            return true;
        };

        for (int i = 1; i < n; ++i){
            // 寻找非递增相邻下标对
            if (nums[i] <= nums[i-1]){
                return check(i - 1) || check(i);
            }
        }
        return true;
    }
};

/**
 * @brief two traverfal from both direction
 * 左到右确定最大值, 统计右边的值小于等于最大值的次数, 如果小于等于1次，证明可以解决.
 * 否则,
 * 从右到左确定最小值，统计左边的值大于等于最小值的次数, 如果小于等于1次，证明可以解决.
 * 否则返回失败
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution_bidirectionTraversal : public Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        if (n <= 2) return true;

        int maxv = nums[0];
        int minv = nums[n - 1];
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= maxv) {
                cnt++;
                if (cnt > 1) break;
            } else maxv = nums[i];
        }
        if (cnt <= 1) return true;
        cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= minv) {
                cnt++;
                if (cnt > 1) return false;
            } else minv = nums[i];
        }

        return true;
    }

private:
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

    solution = new Solution_official();
    cout << "Official             : " << solution->canBeIncreasing(nums) << endl;

    solution = new Solution_bidirectionTraversal();
    cout << "Bidirection Traversal: " << solution->canBeIncreasing(nums) << endl;

    return 0;
}
