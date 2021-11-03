#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        if (n == 2 && (nums[0] + nums[1]) % k != 0) return false;
        unordered_map<int, int> map;
        map[0] = -1;
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = (r + nums[i]) % k;
            if (map.count(r)) {
                int prevIndex = map[r];
                if (i - prevIndex >= 2) return true;
            }
            else map[r] = i;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int n, k;
    vector<int> nums;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.checkSubarraySum(nums, k) << endl;

    //system("pause");
    return 0;
}
