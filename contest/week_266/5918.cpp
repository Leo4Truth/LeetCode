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
    unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u'};
    virtual int countVowelSubstrings(string word) = 0;
};

class Solution_bf : public Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int flag = 0;
                for (int k = i; k <= j; k++) {
                    flag |= helper(word[k]);
                    if (flag > 31) break;
                }
                if (flag > 31) break;
                if (flag == 31) count++;
            }
        }
        return count;
    }

private:
    int helper(char ch) {
        if (ch == 'a') return 1;
        if (ch == 'e') return 2;
        if (ch == 'i') return 4;
        if (ch == 'o') return 8;
        if (ch == 'u') return 16;
        return 32;
    }
};

int main(int argc, char* argv[]) {
    string word = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_bf();
    cout << solution->countVowelSubstrings(word) << endl;

    return 0;
}
