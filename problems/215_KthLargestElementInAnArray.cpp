#include <iostream>
#include <vector>

using namespace std;

class Solution215 {
public:
    /**
     * Quick Selct
     */
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int partion(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        swap(nums, pivotIndex, right);
        int k = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > pivotValue) swap(nums, i, k++);
        }
        swap(nums, k, right);
        return k;
    }

    int select(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pivotIndex = left;
        pivotIndex = partion(nums, left, right, pivotIndex);
        if (k - 1 == pivotIndex) return nums[k - 1];
        else if (k - 1 < pivotIndex) return select(nums, left, pivotIndex - 1, k);
        else if (k - 1 > pivotIndex) return select(nums, pivotIndex + 1, right, k);
        return 0;
    }

    int findKthLargest_quickSelect(vector<int>& nums, int k) {
        return select(nums, 0, nums.size() - 1, k);
    }

    /**
     * Heap Sort
     */
    
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;
    int k = argc >= 3 ? stoi(argv[2]) : 3;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution215 solution;
    cout << solution.findKthLargest(nums, k) << endl;

    //system("pause");
    return 0;
}
