#include <iostream>
#include <vector>

using namespace std;

class Solution77 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n == 0 || n < k) return res;
        vector<bool> used(n + 1, false);
        vector<int> current;
        backtracking(current, used, res, n, k);
        return res;
    }

    void backtracking(vector<int>& current, vector<bool>& used, vector<vector<int>>& res, int n, int k) {
        if (current.size() == k) res.push_back(current);
        else {
            int start = 1;
            if (!current.empty()) start = current[current.size() - 1];
            for (int i = start; i <= n; i++) {
                if (!used[i]) {
                    if (current.empty() || i > current[current.size() - 1]) {
                        used[i] = true;
                        current.push_back(i);
                        backtracking(current, used, res, n, k);
                        current.pop_back();
                        used[i] = false;
                    }
                }
            }
        }
    }
};

int main77() {
    Solution77 solution;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> res = solution.combine(n, k);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j];
            if (j == 0) cout << ", ";
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}