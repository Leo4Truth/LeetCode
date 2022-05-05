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
    virtual int findNumbers(vector<int>& nums) = 0;
};

class Solution_init : public Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (digits(nums[i]) % 2 == 0) cnt++;
        }
        return cnt;
    }

private:
    int digits(int num) {
        if (num == 0) return 1;
        int n = 0;
        while (num > 0) {
            num /= 10;
            n++;
        }
        return n;
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

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->findNumbers(nums) << endl;

    return 0;
}
