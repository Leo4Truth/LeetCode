#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution93 {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string current;
        backtracking(res, current, s, 0);
        return res;
    }

    void backtracking(vector<string>& res, string &current, string s, int depth) {
        if (depth == 3) {
            if (!s.empty() && stoi(s) <= 255) {
                if (s.length() > 1 && s[0] == '0') return;
                int len = current.length();
                current.append(s);
                res.push_back(current);
                current = current.substr(0, len);
            }
            return;
        }
        int maxLeftLen = (4 - depth) * 3;
        int minLeftLen = (4 - depth) * 1;
        if (s.length() < minLeftLen || s.length() > maxLeftLen) return;
        for (int i = 1; i <= 3 && i <= s.length(); i++) {
            string tmp = s.substr(0, i);
            if (stoi(tmp) <= 255) {
                if (tmp.length() > 1 && tmp[0] == '0') continue;
                int len = current.length();
                current.append(tmp);
                current.append(".");
                backtracking(res, current, s.substr(i), depth + 1);
                current = current.substr(0, len);
            }
        }
    }
};

int main93() {
    Solution93 solution;
    string s;
    cin >> s;
    vector<string> res = solution.restoreIpAddresses(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}