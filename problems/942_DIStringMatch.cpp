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
    virtual vector<int> diStringMatch(string s) = 0;
};

class Solution_greedy : public Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length(), lo = 0, hi = n;
        vector<int> perm(n + 1);
        for (int i = 0; i < n; ++i) {
            perm[i] = s[i] == 'I' ? lo++ : hi--;
        }
        perm[n] = lo; // 最后剩下一个数，此时 lo == hi
        return perm;
    }

private:
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";
    int n = s.length();

    Solution *solution = nullptr;

    solution = new Solution_greedy();
    vector<int> perm = solution->diStringMatch(s);
    cout << "greedy: [";
    for (int i = 0; i < n + 1; i++) {
        cout << perm[i];
        if (i < n) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
