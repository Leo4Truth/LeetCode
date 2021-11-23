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
    virtual bool detectCapitalUse(string word) = 0;
};

class Solution_init : public Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 0) return true;
        if (isCapital(word[0])) {
            if (isCapital(word[1])) {
                for (int i = 2; i < n; i++) {
                    if (!isCapital(word[i])) return false;
                }
            }
            else {
                for (int i = 2; i < n; i++) {
                    if (isCapital(word[i])) return false;
                }
            }
        }
        else {
            for (int i = 1; i < n; i++) {
                if (isCapital(word[i])) return false;
            }
        }
        return true;
    }

private:
    bool isCapital(char c) {
        return c >= 'A' && c <= 'Z';
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->detectCapitalUse(s) << endl;

    return 0;
}
