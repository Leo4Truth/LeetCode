#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /* Slide Window or Two Pointers
     * Time  Complexity: O(NlogN), defeat 95.34%
     * Space Complexity: O(1),     defeat 29.73%, no extra space
     * 
     * Ex.
     * nums = [1, 2, 2, 4]
     * k = 5
     * 
     * Turn 0
     *         r
     * origin: 1 2 2 4
     * after:  1 2 2 4  total = 0
     *         l        maxFreq = 1
     * 
     * Turn 1
     *           r
     * origin: 1 2 2 4
     * after:  2 2 2 4  total = 0 + (2 - 1) * (r - l) = 0 + 1 * 1 = 1 < k = 5
     *         l        maxFreq = r - l + 1 = 2
     * 
     * Turn 2
     *             r
     * origin: 1 2 2 4
     * after:  2 2 2 4  total = 1 + (2 - 2) * (r - l) = 1 + 0 * 2 = 1 < k = 5
     *         l        maxFreq = r - l + 1 = 3
     * 
     * Turn 3
     *               r
     * origin: 1 2 2 4
     * after1: 4 4 4 4  total = 1 + (4 - 2) * (r - l) = 1 + 2 * 3 = 7 > k = 5
     *         l      
     * after2: 1 4 4 4  total = 7 - (4 - 1) = 7 - 3 = 4 < k = 5
     *           l      maxFreq = r - l + 1 = 3
     * 
     * return maxFreq = 3
     */
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        long long total = 0;
        int l = 0, maxFreq = 1;
        for (int r = 1; r < n; r++) {
            total += (long long) (nums[r] - nums[r - 1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l];
                l++;
            }
            maxFreq = r - l + 1 > maxFreq ? r - l + 1 : maxFreq;
        }
        return maxFreq;
    }

    // Limit Time Exceeded
    // O(N^2)
    int maxFrequency_enum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        map<int, int, greater<int>> count;
        for (auto num : nums) count[num]++;
        int maxFreq = 0;
        for (auto entry : count) {
            int freq = entry.second;
            int kk = k;
            for (auto entry2 : count) {
                if (entry.first > entry2.first) {
                    int d = entry.first - entry2.first;
                    int cost = d * entry2.second <= kk ? d * entry2.second : kk;
                    int add = cost / d;
                    kk -= cost;
                    freq += add;
                    if (kk == 0) break;
                }
            }
            maxFreq = freq > maxFreq ? freq : maxFreq;
        }
        return maxFreq;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.maxFrequency(nums, k) << endl;

    //system("pause");
    return 0;
}
