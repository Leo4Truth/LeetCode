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
    // DFS
    // Pass
    bool makesquare_dfs(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        int sum = 0;
        for (auto x : matchsticks) sum += x;
        if (sum != sum / 4 * 4) return false;
        int sideLen = sum / 4;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) cnt[matchsticks[i]]++;
        return dfs(cnt, 0, sideLen, 0);
    }

    bool dfs(unordered_map<int, int>& cnt, int sideCnt, int sideLen, int currentSideLen) {
        if (sideCnt == 4) return true;
        for (auto entry : cnt) {
            if (entry.second > 0) {
                if (currentSideLen + entry.first < sideLen) {
                    cnt[entry.first]--;
                    if (dfs(cnt, sideCnt, sideLen, currentSideLen + entry.first)) return true;
                    cnt[entry.first]++;
                }
                else if (currentSideLen + entry.first == sideLen) {
                    cnt[entry.first]--;
                    if (dfs(cnt, sideCnt + 1, sideLen, 0)) return true;
                    cnt[entry.first]++;
                }
            }
        }
        return false;
    }

    // misunderstanding the problem...
    // Not pass
    bool makesquare_fixedOrder(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        int sum = 0;
        for (auto x : matchsticks) sum += x;
        if (sum != sum / 4 * 4) return false;
        int sideLen = sum / 4;
        for (int i = 0; i < n; i++) {
            int sideCnt = 0;
            int currentSideLen = 0;
            for (int j = i; j < n || (j >= n && j - n < i); j++) {
                if (currentSideLen + matchsticks[j] < sideLen) currentSideLen += matchsticks[j];
                else if (currentSideLen + matchsticks[j] == sideLen) {
                    currentSideLen = 0;
                    sideCnt++;
                    if (sideCnt == 4) {
                        if ((j + 1) % n == i) return true;
                        else return false;
                    }
                }
                else return false;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    if (n == 0) cin >> n;
    vector<int> matchsticks;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        matchsticks.push_back(x);
    }

    Solution solution;
    cout << solution.makesquare(matchsticks) << endl;

    //system("pause");
    return 0;
}
