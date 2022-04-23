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
    virtual vector<int> getAverages(vector<int>& nums, int k) = 0;
};

class Solution_init : public Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return {};
        int w = k * 2 + 1;
        vector<int> avg(n, -1);
        if (n < w) return avg;
        
        vector<long long> prefix;
        prefix.push_back(0);
        for (int i = 0; i < n; i++) prefix.push_back(prefix[i] + nums[i]);

        for (int i = k; i < n - k; i++) avg[i] = (prefix[i + k + 1] - prefix[i - k]) / w;

        return avg;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution *solution = nullptr;
    solution = new Solution_init();
    vector<int> avg = solution->getAverages(nums, k);
    cout << "[";
    for (int i = 0; i < avg.size(); i++) {
        cout << avg[i];
        if (i < avg.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
