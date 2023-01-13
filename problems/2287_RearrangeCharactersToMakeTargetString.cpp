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

using namespace std;

class Solution {
public:
    virtual int rearrangeCharacters(string s, string target) = 0;
};

class Solution_hashmap : public Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> sCounts, targetCounts;
        int n = s.size(), m = target.size();
        for (int i = 0; i < m; i++) {
            targetCounts[target[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (targetCounts.count(s[i])) {
                sCounts[s[i]]++;
            }
        }
        int ans = INT_MAX;
        for (auto &[c, count] : targetCounts) {
            int totalCount = sCounts[c];
            ans = min(ans, totalCount / count);
            if (ans == 0) {
                return 0;
            }
        }
        return ans;
    }

private:
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";
    string target = argc >= 3 ? argv[2] : "";

    Solution *solution = nullptr;

    solution = new Solution_hashmap();
    cout << solution->rearrangeCharacters(s, target) << endl;

    return 0;
}
