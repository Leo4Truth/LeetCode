#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    virtual int findLHS(vector<int>& nums) = 0;
};

class Solution_hashmap : public Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int res = 0;
        unordered_map<int, int> map;
        for (auto num : nums) {
            map[num]++;
            if (map.count(num - 1)) res = max(res, map[num - 1] + map[num]);
            if (map.count(num + 1)) res = max(res, map[num + 1] + map[num]);
        }

        return res;
    }
};


class Solution_sort : public Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        sort(nums.begin(), nums.end());
        int prev = 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            if (i > 0 && nums[i] - nums[i - 1] == 1) {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    cnt++;
                    i++;
                }
                res = max(res, cnt + prev);
                prev = cnt;
            }
            else {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    cnt++;
                    i++;
                }
                prev = cnt;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution *solution = nullptr;
    
    solution = new Solution_hashmap();
    cout << "hashmap: " << solution->findLHS(nums) << endl;
    
    solution = new Solution_sort();
    cout << "sort   : " << solution->findLHS(nums) << endl;

    //system("pause");
    return 0;
}
