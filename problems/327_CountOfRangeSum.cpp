#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

struct SegNode {
    int lo, hi, add;
    SegNode* lchild, *rchild;
    SegNode(int left, int right): lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};

class Solution {
public:
    // Pass
    // Time:  720 ms, defeat 31.57%
    // Space: 207.98 MB, defeat 17.63%
    int countRangeSum_MergeSort(vector<int>& nums, int lower, int upper) {
        long s = 0;
        vector<long> sum{0};
        for(auto& v: nums) {
            s += v;
            sum.push_back(s);
        }
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }

    int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
        if (left == right) {
            return 0;
        } else {
            int mid = (left + right) / 2;
            int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
            int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量
            int i = left;
            int l = mid + 1;
            int r = mid + 1;
            while (i <= mid) {
                while (l <= right && sum[l] - sum[i] < lower) l++;
                while (r <= right && sum[r] - sum[i] <= upper) r++;
                ret += (r - l);
                i++;
            }

            // 随后合并两个排序数组
            vector<long> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = sum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = sum[p1++];
                } else {
                    if (sum[p1] < sum[p2]) {
                        sorted[p++] = sum[p1++];
                    } else {
                        sorted[p++] = sum[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                sum[left + i] = sorted[i];
            }
            return ret;
        }
    }

    // Limit Time Exceeded
    // 66/67 passed
    /**
     * @brief 线段树解法
     * 1. 首先建立前缀和数组 preSum ,  preSum[i] 表示 nums[0...i-1] 的和,  preSum[0] 为0
     * 2. 对于每个下标 j ，以 j 为右端点的下标对的数量，就等于数组 preSum[0..j-1] 中的所有整数, 
     *    出现在区间 [preSum[j]-upper, preSum[j]-lower] 的次数. 
     *    故很容易想到基于线段树的解法
     * 3. 我们从左到右扫描前缀和数组. 
     *    每遇到一个数 preSum[j], 我们就在线段树中查询区间 [preSum[j]−upper, preSum[j]−lower] 内的整数数量, 
     *    随后, 将 preSum[j] 插入到线段树当中
     */
    int countRangeSum_SegmentTree(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // prefix sums array
        long long s = 0;
        vector<long long> preSum{0};
        for (int i = 0; i < n; i++) {
            s += nums[i];
            preSum.push_back(s);
        }
        
        // set of all numbers appeared
        set<long long> allNums;
        for (long long x : preSum) {
            allNums.insert(x);
            allNums.insert(x - lower);
            allNums.insert(x - upper);
        }

        // 把出现的整数映射到连续的从0开始的数组
        unordered_map<long long, int> values;
        int index = 0;
        for (long long x : allNums) {
            values[x] = index;
            index++;
        }

        SegNode* root  = build(0, values.size() - 1);
        int res = 0;
        for (long long x : preSum) {
            int left = values[x - upper];       // 离散化
            int right = values[x - lower];      // 离散化
            res += count(root, left, right);
            insert(root, values[x]);
        }

        return res;
    }

private:
    // Segment Tree Operations

    // build segment tree recursively
    SegNode* build(int left, int right) {
        SegNode* node = new SegNode(left, right);
        if (left == right) {
            return node;
        }
        int mid = (left + right) / 2;
        node->lchild = build(left, mid);
        node->rchild = build(mid + 1, right);
        return node;
    }

    // increment all nodes whose range including val
    void insert(SegNode* root, int val) {
        root->add++;
        if (root->lo == root->hi) {
            return;
        }
        int mid = (root->lo + root->hi) / 2;
        if (val <= mid) {
            insert(root->lchild, val);
        }
        else {
            insert(root->rchild, val);
        }
    }
    
    // calculate the sum from left to right
    int count(SegNode* root, int left, int right) const {
        // out of range
        if (left > root->hi || right < root->lo) {
            return 0;
        }
        // the range of current node is fully within [left, right]
        if (left <= root->lo && root->hi <= right) {
            return root->add;
        }
        // otherwise, recursive call
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }

};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    if (n == 0) cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int lower, upper;
    cin >> lower >> upper;
    Solution solution;
    cout << solution.countRangeSum(nums, lower, upper) << endl;

    //system("pause");
    return 0;
}
