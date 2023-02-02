#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <functional> // fuction<>

using namespace std;

class Solution {
public:
    virtual int minStickers(vector<string>& stickers, string target) = 0;
};

class Solution_MemoizedSearchAndStateCompression : public Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.size();
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        function<int(int)> helper = [&](int mask) {
            if (dp[mask] != -1) {
                return dp[mask];
            }
            dp[mask] = m + 1;
            for (auto & sticker : stickers) {
                int left = mask;
                vector<int> cnt(26);
                for (char & c : sticker) {
                    cnt[c - 'a']++;
                }
                for (int i = 0; i < m; i++) {
                    if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0) {
                        cnt[target[i] - 'a']--;
                        left ^= 1 << i;
                    }
                }
                if (left < mask) {
                    dp[mask] = min(dp[mask], helper(left) + 1);
                }
            }
            return dp[mask];
        };
        int res = helper((1 << m) - 1);
        return res > m ? -1 : res;
    }

private:
};

int main(int argc, char* argv[]) {
    string target = argc >= 2 ? argv[1] : "";
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<string> stikers;
    for (int i = 0; i < n; i++) {
        string stiker;
        cin >> stiker;
        stikers.push_back(stiker);
    }

    Solution *solution = nullptr;

    solution = new Solution_MemoizedSearchAndStateCompression();
    cout << solution->minStickers(stikers, target) << endl;

    return 0;
}
