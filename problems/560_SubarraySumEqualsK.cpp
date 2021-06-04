#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        int cnt = 0;
        unordered_map<int, int> map;
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
    cout << solution.subarraySum(nums, k) << endl;

    return 0;
}
