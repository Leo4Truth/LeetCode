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
    virtual int longestSubsequence(vector<int>& arr, int difference) = 0;
};

/**
 * @brief dp[v] = dp[v - difference] + 1
 *        dp[v], length of the longes subsequence end with v
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution_dp_hashmap : public Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if (n == 0) return 0;
        int longest = 1;
        unordered_map<int, int> dp;
        for (auto v : arr) {
            dp[v] = dp[v - difference] + 1;
            longest = dp[v] > longest ? dp[v] : longest;
        }
        return longest;
    }

private:
};

/**
 * @brief dp[], length of the longes subsequence end with arr[i]
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
class Solution_dp : public Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if (n == 0) return 0;
        int longest = 1;
        vector<int> dp(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            int next = arr[i];
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] == next - difference) {
                    next = arr[j];
                    dp[i]++;
                }
            }
            longest = dp[i] > longest ? dp[i] : longest;
        }
        return longest;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int difference = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Solution *solution = nullptr;

    solution = new Solution_dp_hashmap();
    cout << "dp hashmap :" << solution->longestSubsequence(arr, difference) << endl;

    solution = new Solution_dp();
    cout << "dp 1D array:" << solution->longestSubsequence(arr, difference) << endl;

    return 0;
}
