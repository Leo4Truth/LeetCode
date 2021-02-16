#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution784 {
public:
    void dfs(vector<string>& res, string& S, int current) {
        if (current == S.size()) {
            res.push_back(S);
            return;
        }

        if (S[current] >= 'a' && S[current] <= 'z') {
            dfs(res, S, current + 1);
            S[current] -= 32;
            dfs(res, S, current + 1);
            S[current] += 32;
        }
        else if (S[current] >= 'A' && S[current] <= 'Z') {
            dfs(res, S, current + 1);
            S[current] += 32;
            dfs(res, S, current + 1);
            S[current] -= 32;
        }
        else dfs(res, S, current + 1);
    }

    vector<string> letterCasePermutation(string S) {
        int n = S.size();
        if (n == 0) return {};

        vector<string> res;

        dfs(res, S, 0);

        return res;
    }
};

int main(int argc, char* argv[]) {
    string S = argc >= 2 ? argv[1] : "a1b2";

    Solution784 solution;
    vector<string> res = solution.letterCasePermutation(S);

    for (auto perm : res) cout << perm << endl;

    //system("pause");
    return 0;
}

