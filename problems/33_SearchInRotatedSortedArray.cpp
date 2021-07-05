#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search_21_6_29(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;c
            if (nums[mid] == target) return mid;
            // 左半边有序
            if (nums[0] <= nums[mid]) {
                // 若target在左半边范围中, 则下一轮循环搜索左半边
                if (nums[0] <= target && target < nums[mid]) r = mid - 1;
                // 否则下一轮循环搜索右半边
                else l = mid + 1;
            }
            // 左半边无序, 则右半边必定有序
            else {
                // 若target在右半边范围中，则下一轮循环搜索右半边
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                // 否则下一轮循环搜索左半边
                else r = mid - 1;
            }
        }
        return -1;
    }

    // time limit O(logN)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // special cases
        if (n == 0) return -1;
        if (n == 1 && nums[0] == target) return 0;
        
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            else { // nums[mid] > nums[right]
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums;
    int n, x, target;
    cout << "input size of the array: " << endl;
    cin >> n;
    cout << "input " << n << " elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    cout << "input target: " << endl;
    cin >> target;
    Solution33 solution;
    cout << "result = " << solution.search(nums, target) << endl;
    system("pause");
    return 0;
}