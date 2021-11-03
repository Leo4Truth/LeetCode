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
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        if (n == 0) return s;

        string reformatted = "";
        int nn = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '-') {
                if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] + 'A' - 'a';
                reformatted.append(s.substr(i, 1));
                nn++;
            }
        }
        
        int cnt = 0;
        for (int i = nn - 1; i >= 0; i--) {
            if (cnt == k - 1 && i != 0) {
                reformatted.insert(i, "-");
                cnt = 0;
            } else cnt++;
        }
        
        return reformatted;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";
    int k = argc >= 3 ? stoi(argv[2]) : 0;

    Solution solution;
    cout << solution.licenseKeyFormatting(s, k) << endl;

    return 0;
}
