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
    virtual bool divisorGame(int n) = 0;
};

class Solution_math : public Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
        //return !(n&1);
    }
};

class Solution_dp : public Solution {
public:
    bool divisorGame(int n) {
        // whether Alice win with n
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int nn = 1; nn <= n; nn++) {
            for (int x = 1; x <= nn / 2; x++) {
                if (nn % x == 0 && !dp[nn - x]) {
                    dp[nn] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 1;

    Solution *solution = nullptr;
    
    solution = new Solution_math();
    cout << "math: " << solution->divisorGame(n) << endl;
    
    solution = new Solution_dp();
    cout << "dp  : " << solution->divisorGame(n) << endl;

    return 0;
}
