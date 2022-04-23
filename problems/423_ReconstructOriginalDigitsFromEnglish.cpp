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
    virtual string originalDigits(string s) = 0;
};

class Solution_init : public Solution {
public:
    Solution_init() {
        cost[0].push_back(make_pair('z', 1));
        cost[0].push_back(make_pair('e', 1));
        cost[0].push_back(make_pair('r', 1));
        cost[0].push_back(make_pair('o', 1));
        
        cost[1].push_back(make_pair('o', 1));
        cost[1].push_back(make_pair('n', 1));
        cost[1].push_back(make_pair('e', 1));
        
        cost[2].push_back(make_pair('t', 1));
        cost[2].push_back(make_pair('w', 1));
        cost[2].push_back(make_pair('o', 1));

        cost[3].push_back(make_pair('t', 1));
        cost[3].push_back(make_pair('h', 1));
        cost[3].push_back(make_pair('r', 1));
        cost[3].push_back(make_pair('e', 2));

        cost[4].push_back(make_pair('f', 1));
        cost[4].push_back(make_pair('o', 1));
        cost[4].push_back(make_pair('u', 1));
        cost[4].push_back(make_pair('r', 1));

        cost[5].push_back(make_pair('f', 1));
        cost[5].push_back(make_pair('i', 1));
        cost[5].push_back(make_pair('v', 1));
        cost[5].push_back(make_pair('e', 1));
        
        cost[6].push_back(make_pair('s', 1));
        cost[6].push_back(make_pair('i', 1));
        cost[6].push_back(make_pair('x', 1));

        cost[7].push_back(make_pair('s', 1));
        cost[7].push_back(make_pair('e', 2));
        cost[7].push_back(make_pair('v', 1));
        cost[7].push_back(make_pair('n', 1));

        cost[8].push_back(make_pair('e', 1));
        cost[8].push_back(make_pair('i', 1));
        cost[8].push_back(make_pair('g', 1));
        cost[8].push_back(make_pair('h', 1));
        cost[8].push_back(make_pair('t', 1));
        
        cost[9].push_back(make_pair('n', 2));
        cost[9].push_back(make_pair('i', 1));
        cost[9].push_back(make_pair('e', 1));
    }

    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }

private:
    vector<vector<pair<char, int>>> cost(10);
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->originalDigits(s) << endl;

    return 0;
}
