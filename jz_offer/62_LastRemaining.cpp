#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual int lastRemaining(int n, int m) = 0;
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pass
// 0 1 2 ... m-2 m-1  m  m+1 ... n-1
// 0 1 2 ... m-2     m-1  m  ... n-2
// Notice: index start from 0
class Solution_iterative : public Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for (int i = 2; i != n + 1; ++i) f = (m + f) % i;
        return f;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pass
// 0 1 2 ... m-2 m-1  m  m+1 ... n-1
// 0 1 2 ... m-2     m-1  m  ... n-2
// Notice: index start from 0
class Solution_recursive : public Solution {
public:
    int lastRemaining(int n, int m) {
        return n == 1 ? 0 : (lastRemaining(n - 1, m) + m) % n;
    }
};

// Time Complexity: O(mn)
// Space Complexity: O(n)
// Limit Time Exceeded
class Solution_simulate : public Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> nums;
        for (int i = 0; i < n; i++) nums.push_back(i);
        int remove = (m - 1) % nums.size();
        while (nums.size() > 1) {
            nums.erase(nums.begin() + remove);
            remove = (remove + m - 1) % nums.size();
        }
        return nums[0];
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_simulate();
    cout << "simulate:  " << solution->lastRemaining(n, m) << endl;

    solution = new Solution_recursive();
    cout << "recursive: " << solution->lastRemaining(n, m) << endl;

    solution = new Solution_iterative();
    cout << "iterative: " << solution->lastRemaining(n, m) << endl;
    
    return 0;
}
