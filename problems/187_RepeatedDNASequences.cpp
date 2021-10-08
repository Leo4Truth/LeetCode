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
private:
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

public:
    vector<string> findRepeatedDnaSequences_0(string s) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for (int i = 0; i <= n - L; ++i) {
            string sub = s.substr(i, L);
            if (++cnt[sub] == 2) {
                ans.push_back(sub);
            }
        }
        return ans;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.length();
        if (n <= L) {
            return ans;
        }
        int x = 0;
        for (int i = 0; i < L - 1; ++i) {
            x = (x << 2) | bin[s[i]];
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - L; ++i) {
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
            if (++cnt[x] == 2) {
                ans.push_back(s.substr(i, L));
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution solution;
    vector<string> seqs = solution.findRepeatedDnaSequences(s);
    cout << "[";
    for (int i = 0; i < seqs.size(); i++) {
        cout << "\"" << seqs[i] << "\"";
        if (i < seqs.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
