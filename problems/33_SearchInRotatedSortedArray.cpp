#include <iostream>
#include <vector>

using namespace std;

class Solution33 {
public:
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

int main33() {
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