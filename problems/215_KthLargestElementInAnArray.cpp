#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // min heap
    // pass
    // Time:  O(NlogK),     8 ms, defeat 88.82%
    // Space: O(K),       9.8 MB, defeat 34.36%
    int findKthLargest_minHeap(vector<int>& nums, int k) {
        // 对前k个元素建成小根堆
        for (int i = 0; i < k; i++) {
            swim(nums, i);
        }
        // 剩下的元素与堆顶比较，若大于堆顶则去掉堆顶，再将其插入
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                swap(nums[0], nums[i]);
                sink(nums, 0, k - 1);
            }
        }
        // 结束后第k个大的数就是小根堆的堆顶
        return nums[0];
    }

    // 若v1比v2优先度高，返回true
    bool cmp(int v1, int v2) { return v1 < v2; }

    // 上浮 从下到上调整堆
    void swim(vector<int>& heap, int i) {
        while (i > 0 && cmp(heap[i], heap[(i - 1) / 2])) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // 下沉 从下到上调整堆
    void sink(vector<int>& heap, int i, int N) {
        while (2 * i + 1 <= N) {
            int j = 2 * i + 1;
            if (j + 1 <= N && cmp(heap[j + 1], heap[j])) {
                j++;
            }
            if (cmp(heap[i], heap[j])) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    }

    // max heap
    // pass
    // Time:  O(NlogN),     8 ms, defeat 88.82%
    // Space: O(N),       9.8 MB, defeat 25.93%
    int findKthLargest_maxHeap(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }

    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    // Quick Select
    int findKthLargest_quickSelect(vector<int>& nums, int k) {
        return select(nums, 0, nums.size() - 1, k);
    }

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
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 10;
    int k = argc >= 3 ? stoi(argv[2]) : 1;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        nums.push_back(i);
        cout << nums[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}