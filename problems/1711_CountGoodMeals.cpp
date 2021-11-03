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
    int countPairs(vector<int>& deliciousness) {
        // 1e9+7吧 是一个很大的质数，而且刚好相加不会爆int，相乘不会爆long long
        const static int MOD = 1000000007;
        int n = deliciousness.size();
        if (n == 0) return 0;
        int maxSum = (*max_element(deliciousness.begin(), deliciousness.end())) * 2;
        int res = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            for (int sum = 1; sum <= maxSum; sum <<= 1) {
                int count = map.count(sum - deliciousness[i]) ? map[sum - deliciousness[i]] : 0;
                res = (res + count) % MOD;
            }
            map[deliciousness[i]]++;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    if (n == 0) cin >> n;
    vector<int> deliciousness;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        deliciousness.push_back(x);
    }

    Solution solution;
    cout << solution.countPairs(deliciousness) << endl;

    //system("pause");
    return 0;
}
