#include <iostream>
#include <vector>

using namespace std;

class Solution39 {
public:
    // allow duplicate use of candidates
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> res;
        backtrack(results, 0, res, candidates, target);
        return results;
    }

    void backtrack(vector<vector<int>>& results, int s, vector<int>& res, vector<int>& candidates, int target) {
        //cout << "target = " << target << endl;
        //cout << "res = " << endl;
        //print(res);
        for (int i = s; i < candidates.size(); i++) {
            if (candidates[i] < target) {
                res.push_back(candidates[i]);
                backtrack(results, i, res, candidates, target - candidates[i]);
                res.pop_back();
            }
            else if (candidates[i] == target) {
                res.push_back(candidates[i]);
                results.push_back(res);
                res.pop_back();
            }
        }
    }

    void print(vector<int> res) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
};

int main39() {
    vector<int> candidates;
    int target;
    Solution39 solution;

    int n, x;
    cout << "input n: " << endl;
    cin >> n;
    cout << "input " << n << " candidates: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        candidates.push_back(x);
    }
    cout << "input target: " << endl;
    cin >> target;
    vector<vector<int>> results = solution.combinationSum(candidates, target);
    cout << "results = [" << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << "    [";
        for (int j = 0; j < results[i].size() - 1; j++) {
            cout << results[i][j] << ", ";
        }
        cout << results[i][results[i].size() - 1] << "], " << endl;
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}