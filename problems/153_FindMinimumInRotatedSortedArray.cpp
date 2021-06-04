#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution153 {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        int min = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < min) return nums[i];
        }
        return min;
    }
    
    int findMin_binary_search(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int left = 0, right = n - 1;
        if (nums[right] > nums[0]) return nums[0];
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if (nums[mid - 1] > nums[mid]) return nums[mid];
            if (nums[mid] > nums[0]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
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

    Solution153 solution;
    cout << solution.findMin(nums) << endl;

    //system("pause");
    return 0;
}

