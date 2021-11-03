#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int n2 = nums2.size();
        if (n == 0 || n2 == 0 || n != n2) return 0;
        vector<int> nums1_sorted(nums1);
        sort(nums1_sorted.begin(), nums1_sorted.end());
        int sum = 0;
        int maxn = 0;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % MOD;
            // binary search for j maxify |nums1[i] - nums2[i]| - |nums1[j] - nums2[i]|
            int j = lower_bound(nums1_sorted.begin(), nums1_sorted.end(), nums2[i]) - nums1_sorted.begin();
            if (j < n) maxn = max(maxn, diff - (nums1_sorted[j] - nums2[i]));       // left side
            if (j > 0 ) maxn = max(maxn, diff - (nums2[i] - nums1_sorted[j - 1]));  // right side
        }
        return (sum - maxn + MOD) % MOD;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    if (n == 0) cin >> n;
    vector<int> nums1, nums2;
    for (int i = 0; i < n; i++) {
        int n1;
        cin >> n1;
        nums1.push_back(n1);
    }
    for (int i = 0; i < n; i++) {
        int n2;
        cin >> n2;
        nums2.push_back(n2);
    }

    Solution solution;
    cout << solution.minAbsoluteSumDiff(nums1, nums2) << endl;

    //system("pause");
    return 0;
}
