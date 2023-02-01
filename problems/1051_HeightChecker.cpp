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
    virtual int heightChecker(vector<int>& heights) = 0;
};

class Solution_init : public Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        if (n == 0 || n == 1) return 0;
        vector<int> expected;
        for (int height : heights) expected.push_back(height);
        sort(expected.begin(), expected.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != expected[i]) cnt++;
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        heights.push_back(height);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->heightChecker(heights) << endl;

    return 0;
}
