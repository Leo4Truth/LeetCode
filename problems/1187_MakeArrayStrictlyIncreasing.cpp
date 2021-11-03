#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxv = 1e9;

    // 1d dp
    int makeArrayIncreasing_dp_1d(vector<int>& arr1, vector<int>& arr2) {
        // 预处理：排序，去重，加哨兵
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        arr1.push_back(maxv + 5); // 右侧哨兵 inf
        arr1.insert(arr1.begin(), -1); // 左侧哨兵 -1

        // dp[i] is the min operations needed to keep arr1[i] and make arr[0...i] strictly increasing
        vector<int> dp(arr1.size(), maxv);
        dp[0] = 0;
        for (int i = 1; i < arr1.size(); ++i) {

            // 1. 替换 a[i - 1], 希望 a[i - 1] 尽量大
            // 二分查找 arr2 中第一个 大于等于 arr1[i] 的元素 arr2[j], 将 arr1[i - 1] 替换为 arr2[j - 1] (如果有)
            // 继续考虑是否替换 arr1[i - 2], arr1[i - 1] 此时已经是 arr2[j - 1], 故 arr1[i - 2] 应当替换为 arr2[j - 2] (如果有)
            // 继续考虑是否替换 arr1[i - 3], 以此类推
            // lower_bound(first, last, val) func return the first element in range [first, last) not less than val
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            for (int k = 1; k <= min(i - 1, j); k++){ // 枚举替换的个数 k = 1 to min(i - 1, j)
                if (arr1[i - k - 1] < arr2[j - k]) { // k <= i - 1, so i - k - 1 >= 0
                    dp[i] = min(dp[i], dp[i - k - 1] + k);
                }
            }

            // 2. 不替换 arr1[i - 1]
            if (arr1[i - 1] < arr1[i]) {
                dp[i] = min(dp[i], dp[i - 1]);
            }
        }

        int res = dp[arr1.size() - 1];
        return (res >= maxv)? -1 : res;
    }
};

int main(int argc, char* argv[]) {
    int n1 = argc >= 2 ? stoi(argv[1]) : 0;
    int n2 = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        arr1.push_back(x);
    }
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        arr2.push_back(x);
    }

    Solution solution;
    cout << solution.makeArrayIncreasing(arr1, arr2) << endl;

    return 0;
}
