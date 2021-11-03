#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
    static constexpr int mod = 1000000007;
    
    using LL = long long;

public:
    int sumOfFlooredPairs(vector<int>& nums) {
        // 元素最大值
        int upper = *max_element(nums.begin(), nums.end());
        // vector<int>存频数
        vector<int> cnt(upper + 1);
        for (int num: nums) {
            ++cnt[num];
        }
        // 预处理前缀和
        // pre[i]代表 1 ~ i 的频数之和
        // i 的频数 cnt[i] = pre[i] - pre[i - 1]
        vector<int> pre(upper + 1);
        for (int i = 1; i <= upper; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        
        LL ans = 0;
        for (int y = 1; y <= upper; ++y) {
            // 一个小优化，如果数组中没有 y 可以跳过
            if (cnt[y]) {
                // y 代表除数
                // d 代表商
                // 则被除数的范围为 [d * y, (d + 1) * y - 1]
                // 考虑 nums 数组中数的上届 upper, 被除数上界为 min((d + 1) * y - 1, upper)
                // 那么被除数的频数为 pre[被除数上界] - pre[被除数下届 - 1]
                // 又除数的频数为 cnt[y]
                // 所以 商为 d 的所有 pair 的商之和为 (商 * 除数频数 * 被除数频数)
                for (int d = 1; d * y <= upper; ++d) {
                    ans += (LL)cnt[y] * d * (pre[min((d + 1) * y - 1, upper)] - pre[d * y - 1]);
                }
            }
        }
        return ans % mod;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.sumOfFlooredPairs(nums) << endl;

    //system("pause");
    return 0;
}
