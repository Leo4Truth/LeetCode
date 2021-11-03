#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution1332 {
public:
    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] != s[hi]) return false;
            lo++;
            hi--;
        }
        return true;
    }

    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        if (isPalindrome(s)) return 1;
        return 2;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "ababaa";

    Solution1332 solution;
    cout << solution.removePalindromeSub(s) << endl;

    //system("pause");
    return 0;
}

