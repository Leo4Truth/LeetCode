#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Limit time execeed
    int maxOperations_1(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        vector<bool> done(n, false);
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            if (!map.count(nums[i])) map[nums[i]] = vector<int>{i};
            else map[nums[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (done[i]) continue;
            int target = k - nums[i];
            if (map.count(target)) {
                for (int j = 0; j < map[target].size(); j++) {
                    if (!done[map[target][j]] && map[target][j] != i) {
                        done[i] = true;
                        done[map[target][j]] = true;
                        cnt++;
                        break;
                    }
                }
            }
        }

        return cnt;
    }

    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) map[nums[i]]++;

        for (int i = 0; i < n; i++) {
            if (map[nums[i]] > 0 && map.count(k - nums[i])) {
                map[nums[i]]--;
                if (map[k - nums[i]] > 0) {
                    map[k - nums[i]]--;
                    cnt++;
                }
                else {
                    map[nums[i]]++;
                    continue;
                }
            }
        }

        return cnt;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;
    int k = argc >= 3 ? stoi(argv[2]) : n;

    cout << "n=" << n << ", k=" << k << endl;
    cout << "please input " << n << " nums: " << endl;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.maxOperations(nums, k) << endl;

    return 0;
}
