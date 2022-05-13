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
    virtual int minDeletionSize(vector<string>& strs) = 0;
};

class Solution_init : public Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return 0;
        int m = strs[0].length();
        if (m == 0) return 0;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strs.push_back(str.substr(0, m));
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->minDeletionSize(strs) << endl;

    return 0;
}
