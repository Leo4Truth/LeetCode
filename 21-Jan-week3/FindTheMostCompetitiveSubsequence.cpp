#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || n < k) return {};
        if (n == k) return nums;

        vector<int> res;
        deque<int> deq;
        deq.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            while (!deq.empty() && nums[i] < deq.back() && k - deq.size() < n - i) deq.pop_back();
            if (deq.size() < k) deq.push_back(nums[i]);
        }

        for (int i = 0; i < k; i++) {
            res.push_back(deq.front());
            deq.pop_front();
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 4;
    int k = argc >= 3 ? stoi(argv[2]) : 2;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    vector<int> res = solution.mostCompetitive(nums, k);

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
