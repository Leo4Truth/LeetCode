#include <iostream>
#include <vector>

using namespace std;

class Solution75 {
public:
    void sortColors_countingSort(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt0 += nums[i] == 0 ? 1 : 0;
            cnt1 += nums[i] == 1 ? 1 : 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < cnt0) nums[i] = 0;
            else if (i < cnt0 + cnt1) nums[i] = 1;
            else nums[i] = 2;
        }
    }

    // li                       r
    // 0 2 0 1 0 1 0 1 2 1 2 0 1

    // l i                     r
    // 0 2 0 1 0 1 0 1 2 1 2 0 1
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] == 2 && i < r) {
                int tmp = nums[i];
                nums[i] = nums[r];
                nums[r] = tmp;
                r--;
            }
            while (nums[i] == 0 && i > l) {
                int tmp = nums[i];
                nums[i] = nums[l];
                nums[l] = tmp;
                l++;
            }
        }
    }
};

int main75() {
    Solution75 solution;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << x;
        nums.push_back(x);
    }
    solution.sortColors(nums);
    system("pause");
    return 0;
}