#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// tricky method
bool isPowerOfTwo(int n) {
    // binary
    // 1000000 & 0111111 = 0
    // 100 & 011 = 0
    return (n & (n - 1)) == 0;
}

// prehandle for Solution_prehandle_hash
unordered_set<string> powerOfTwoDigits;

string countDigits(int n) {
    string cnt(10, 0); // n <= 10^9
    while (n) {
        ++cnt[n % 10];
        n /= 10;
    }
    return cnt;
}

int init = []() {
    for (int n = 1; n <= 1e9; n <<= 1) {
        powerOfTwoDigits.insert(countDigits(n));
    }
    return 0;
}();

class Solution {
public:
    virtual bool reorderedPowerOf2(int n) = 0;
};

class Solution_prehandle_hash : public Solution {
public:
    bool reorderedPowerOf2(int n) {
        return powerOfTwoDigits.count(countDigits(n));
    }
};

class Solution_dfs : public Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> digits;
        int len = 0;
        while (n > 0) {
            digits[n % 10]++;
            n /= 10;
            len++;
        }
        dfs(digits, len, 0, 0);
        return found;
    }

    void dfs(unordered_map<int, int>& digits, int maxlen, int curlen, int num) {
        if (curlen == maxlen && isPowerOfTwo(num)) {
            found = true;
            return;
        }
        for (auto& entry : digits) {
            if (entry.second > 0) {
                if (entry.first == 0 && curlen == 0) continue;
                entry.second--;
                dfs(digits, maxlen, curlen + 1, num * 10 + entry.first);
                entry.second++;
            }
        }
    }

private:
    bool found = false;
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = new Solution_dfs();
    cout << "Solution_dfs           : " << solution->reorderedPowerOf2(n) << endl;

    solution = new Solution_prehandle_hash();
    cout << "Solution_prehandle_hash: " << solution->reorderedPowerOf2(n) << endl;
    
    return 0;
}
