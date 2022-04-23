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
    virtual long long countVowels(string word) = 0;
};

class Solution_multiplication : public Solution {
public:
    long long countVowels(string word) {
        unordered_set<char> vowel;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        int n = word.length();
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            if (vowel.count(word[i]) == 1) {
                sum += (i + 1) * (n - i);
            }
        }
        return sum;
    }

private:
};

/**
 * @brief dp
 * Limited
 *  Time Exceeded
 * dp[i][j] #vowel in word[i][j]
 */
class Solution_dp : public Solution {
public:
    long long countVowels(string word) {
        unordered_set<char> vowel;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        int n = word.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = vowel.count(word[0]) == 1;
        for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + (vowel.count(word[i]) == 1);
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++){
                dp[i][j] = dp[i - 1][j] - (vowel.count(word[i - 1]) == 1);
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }

private:
};

int main(int argc, char* argv[]) {
    string word = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_multiplication();
    cout << "multiplication: " << solution->countVowels(word) << endl;

    solution = new Solution_dp();
    cout << "dp (LTE)      : " << solution->countVowels(word) << endl;

    return 0;
}
