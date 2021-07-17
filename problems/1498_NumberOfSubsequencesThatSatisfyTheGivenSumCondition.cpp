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
    static constexpr int P = int(1E9) + 7;
    static constexpr int MAX_N = int(1E5) + 5;

    int f[MAX_N];

    void pretreatment() {
        f[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            f[i] = (long long)f[i - 1] * 2 % P;
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        pretreatment();

        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < nums.size() && nums[i] * 2 <= target; ++i) {
            int maxValue = target - nums[i];
            int pos = upper_bound(nums.begin(), nums.end(), maxValue) - nums.begin() - 1;
            int contribute = (pos >= i) ? f[pos - i] : 0;
            ans = (ans + contribute) % P;
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int target = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.numSubseq(nums, target) << endl;

    //system("pause");
    return 0;
}
