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
    virtual int minCost(string colors, vector<int>& neededTime) = 0;
};

class Solution_init : public Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if (n != neededTime.size()) return -1;
        int cost = 0;
        for (int i = 0; i < n; ) {
            int sum = 0;
            int j = i;
            while (j < n && colors[i] == colors[j]) sum += neededTime[j++];
            cost += singleCost(i, j - 1, neededTime);
            i = j;
        }
        return cost;
    }

private:
    int singleCost(int l, int r, vector<int>& neededTime) {
        if (l < 0 || r >= neededTime.size() || l > r) return -1;
        int max = INT32_MIN;
        int total = 0;
        for (int i = l; i <= r; i++) {
            max = neededTime[i] > max ? neededTime[i] : max;
            total += neededTime[i];
        }
        return total - max;
    }
};

int main(int argc, char* argv[]) {
    string colors = argc >= 2 ? argv[1] : "";
    int n = colors.size();
    vector<int> neededTime;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        neededTime.push_back(t);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->minCost(colors, neededTime) << endl;

    return 0;
}
