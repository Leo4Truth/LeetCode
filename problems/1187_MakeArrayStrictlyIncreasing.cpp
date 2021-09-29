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
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // 预处理：排序，去重，加哨兵
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        arr1.push_back(maxv + 5); // 右侧哨兵 inf
        arr1.insert(arr1.begin(), -1); // 左侧哨兵 -1

        vector<int> dp(arr1.size(), maxv);
        dp[0] = 0;
        for(int i = 1; i < arr1.size(); ++i) {
            int j = lower_bound(arr2.begin(),arr2.end(), arr1[i]) - arr2.begin();
            for(int k = 1; k <= min(i-1,j); ++k){ // 1. 枚举替换的个数 k = 1 to min(i-1,j)
                if(arr1[i-k-1] < arr2[j-k]) {
                    dp[i] = min(dp[i], dp[i-k-1] + k);
                }
            }
            if(arr1[i-1] < arr1[i]) { // 2. 不替换 arr1[i-1]
                dp[i] = min(dp[i], dp[i-1]);
            }
        }

        int res = dp[arr1.size()-1];
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
