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
    virtual bool buddyStrings(string s, string goal) = 0;
};

class Solution_init : public Solution {
public:
    bool buddyStrings(string s, string goal) {
        int len = s.size();
        if (len != goal.size()) return false;
        unordered_map<char, int> map;
        bool repeat = false;
        int diffIdx[2] = {-1, -1};
        int diffCnt = 0;
        for (int i = 0; i < len; i++) {
            map[s[i]]++;
            if (map[s[i]] >= 2) repeat = true;
            if (s[i] != goal[i]) {
                diffCnt++;
                if (diffCnt > 2) return false;
                diffIdx[diffCnt - 1] = i;
            }
        }
        if (diffCnt == 0) return repeat;
        return diffCnt == 2 && s[diffIdx[0]] == goal[diffIdx[1]] && s[diffIdx[1]] == goal[diffIdx[0]];
    }

private:
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";
    string goal = argc >= 3 ? argv[2] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->buddyStrings(s, goal) << endl;

    return 0;
}
