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
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] -= ('A' - 'a');
        }
        return s;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution solution;
    cout << solution.toLowerCase(s) << endl;

    return 0;
}
