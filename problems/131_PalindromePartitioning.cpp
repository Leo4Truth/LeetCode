#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution131 {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }

    void backtrack(string& s, vector<vector<string>>& res, vector<string>& partition, int pos) {
        int n = s.size();
        if (pos == n) {
            res.push_back(partition);
            return;
        }
        
        for (int r = pos; r < n; r++) {
            int len = r - pos + 1;
            if (isPalindrome(s.substr(pos, len))) {
                partition.push_back(s.substr(pos, len));
                backtrack(s, res, partition, pos + len);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        if (n == 0) return {};

        vector<vector<string>> res;
        vector<string> partition;
        backtrack(s, res, partition, 0);

        return res;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "aab";

    Solution131 solution;
    vector<vector<string>> res = solution.partition(s);

    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "\t[";
        for (int j = 0; j <res[i].size(); j++) {
            cout << "\"" << res[i][j] << "\"";
            if (j < res[i].size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}
