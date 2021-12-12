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

#define DEBUG

using namespace std;

class Solution {
public:
    virtual int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) = 0;
};

class Solution_twoPointers : public Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = solve(fruits, startPos, k);
        
        for (auto &fruit : fruits)
            fruit[0] = -fruit[0];
        reverse(fruits.begin(), fruits.end());
        ans = max(ans, solve(fruits, -startPos, k));
        
        return ans;
    }

private:
    int solve(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int p = upper_bound(fruits.begin(), fruits.end(), vector<int>{startPos, INT32_MAX}) - fruits.begin() - 1;
        int ans = 0, r = 0, sum = 0;
        for (int i = 0; i <= p; ++i)
            sum += fruits[i][1];

        for (int l = 0; l <= p; ++l) {
            if (l >= 1)
                sum -= fruits[l - 1][1];
            if (startPos - fruits[l][0] > k)
                continue;
            r = max(r, l);
            while (r + 1 < n && startPos - fruits[l][0] + fruits[r + 1][0] - fruits[l][0] <= k) {
                r++;
                if (r > p)
                    sum += fruits[r][1];
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int startPos = argc >= 3 ? stoi(argv[2]) : 0;
    int k = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> fruits;
    for (int i = 0; i < n; i++) {
        int position;
        int amount;
        cin >> position >> amount;
        fruits.push_back({position, amount});
    }

    Solution *solution = nullptr;

    solution = new Solution_twoPointers();
    cout << "twoPointers: " << solution->maxTotalFruits(fruits, startPos, k) << endl;

    return 0;
}
