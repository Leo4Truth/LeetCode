#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int *a = nullptr, *b = nullptr, *c = nullptr;
        for (int &num : nums) {
            if (a == nullptr || num > *a) {
                c = b;
                b = a;
                a = &num;
            } else if (*a > num && (b == nullptr || num > *b)) {
                c = b;
                b = &num;
            } else if (b != nullptr && *b > num && (c == nullptr || num > *c)) {
                c = &num;
            }
        }
        return c == nullptr ? *a : *c;
    }
    
    int thirdMax_0(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        priority_queue<int, vector<int>> q;
        for (auto num : nums) q.push(num);
        int max = q.top();

        unordered_set<int> set;
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            set.insert(x);
            if (set.size() == 3) return x;
            else if (q.empty()) return max;
        }
        
        return -1;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution solution;
    cout << solution.thirdMax(nums) << endl;
    
    return 0;
}
