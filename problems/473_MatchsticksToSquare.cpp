#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool makesquare_dfs_prune(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        int sum = 0;
        for (auto x : matchsticks) sum += x;
        if (sum != sum / 4 * 4) return false;
        int sideLen = sum / 4;
        sort(matchsticks.begin(), matchsticks.end());
        return dfs1(matchsticks, 0, sideLen, 0);
    }

    bool dfs1(vector<int>& matchsticks, int index, int sideLen, int currentSideLen) {
        if (index == matchsticks.size()) return true;
        for (int i = index; i < matchsticks.size(); i++) {
            
        }
        return false;
    }

    // DFS
    // Pass
    // 2022.06.01: Limited Time Exceeded, need pruning
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

    vector<int> new_case = {4,13,1,1,14,15,1,3,13,1,3,5,2,8,12};

    Solution solution;
    cout << "input   : " << solution.makesquare_dfs_prune(matchsticks) << endl;
    cout << "new case: " << solution.makesquare_dfs_prune(new_case) << endl;

    //system("pause");
    return 0;
}
