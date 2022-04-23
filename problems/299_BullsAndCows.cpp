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
    virtual string getHint(string secret, string guess) = 0;
};

class Solution_official : public Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                ++cntS[secret[i] - '0'];
                ++cntG[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i) {
            cows += min(cntS[i], cntG[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }

private:
};

int main(int argc, char* argv[]) {
    string secret = argc >= 2 ? argv[1] : "";
    string guess = argc >= 3 ? argv[2] : "";

    Solution *solution = nullptr;

    solution = new Solution_official();
    cout << "origin: " << solution->getHint(secret, guess) << endl;

    return 0;
}
