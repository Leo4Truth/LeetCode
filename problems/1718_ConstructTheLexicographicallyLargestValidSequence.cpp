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
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2 * n - 1, -1);
        vector<bool> used(n + 1, false);
        if (dfs(seq, used, 0)) return seq;
        return {};
    }

    bool dfs(vector<int>& seq,vector<bool>& used, int pos) {
        if (pos == seq.size()) return true;
        if (seq[pos] != -1) return dfs(seq, used, pos + 1);
        for (int i = used.size() - 1; i > 1; i--) {
            if (used[i]) continue;
            if (pos + i >= seq.size() || seq[pos + i] != -1) continue;
            seq[pos] = i;
            seq[pos + i] = i;
            used[i] = true;
            if (dfs(seq, used, pos + 1)) return true;
            used[i] = false;
            seq[pos + i] = -1;
            seq[pos] = -1;
        }
        if (!used[1]) {
            used[1] = true;
            seq[pos] = 1;
            if (dfs(seq, used, pos + 1)) return true;
            seq[pos] = -1;
            used[1] = false;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    vector<int> seq = solution.constructDistancedSequence(n);
    for (auto x : seq) cout << x << " ";
    cout << endl;

    //system("pause");
    return 0;
}
