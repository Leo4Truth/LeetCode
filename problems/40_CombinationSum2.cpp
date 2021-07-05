#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution40 {
public:
    // No duplicate elements in any result

    // dfs
    // Pass
    // Time:  4 ms,    defeat 92.94%
    // Space: 10.3 MB, defeat 78.35%
    vector<vector<int>> combinationSum2_dfs(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0) return {};
        vector<vector<int>> res;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) map[candidates[i]]++;
        vector<int> current;
        dfs(map, target, current, res);
        return res;
    }

    void dfs(unordered_map<int, int>& map, int target, vector<int>& current, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(current);
            return;
        }
        for (auto entry : map) {
            if (entry.first <= target && entry.second > 0 && 
                (current.empty() || entry.first >= current.back())) { // To ensure no duplicate, make each combination ascending order
                current.push_back(entry.first);
                map[entry.first]--;
                dfs(map, target - entry.first, current, res);
                map[entry.first]++;
                current.pop_back();
            }
        }
    }

    // solution 1, origin, time faster than 46%
    /*
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<pair<int, int>> candidatesCount;
        for (int i = 0; i < candidates.size(); i++) {
            bool exist = false;
            for (int j = 0; j < candidatesCount.size(); j++) {
                if (candidatesCount[j].first == candidates[i]) {
                    candidatesCount[j].second += 1;
                    exist = true;
                    break;
                }
            }
            if (!exist) candidatesCount.push_back(pair<int, int>(candidates[i], 1));
        }
        for (int i = 0; i < candidatesCount.size(); i++) {
            cout << candidatesCount[i].first << ", " << candidatesCount[i].second << endl;
        }
        vector<int> res;
        backtrack(results, 0, res, candidatesCount, target);
        return results;
    }

    void backtrack(vector<vector<int>>& results, int s, vector<int>& res, vector<pair<int, int>>& candidatesCount, int target) {
        for (int i = s; i < candidatesCount.size(); i++) {
            if (candidatesCount[i].second == 0) continue;
            if (candidatesCount[i].first < target && candidatesCount[i].second > 0) {
                candidatesCount[i].second--;
                res.push_back(candidatesCount[i].first);
                backtrack(results, i, res, candidatesCount, target - candidatesCount[i].first);
                res.pop_back();
                candidatesCount[i].second++;
            }
            else if (candidatesCount[i].first == target && candidatesCount[i].second > 0) {
                //candidatesCount[i].second--;
                res.push_back(candidatesCount[i].first);
                results.push_back(res);
                res.pop_back();
                //candidatesCount[i].second++;
            }
        }
    }
    */

    // solution 2, sort, faster than 86%
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        backtrack(results, 0, res, candidates, target);
        return results;
    }

    void backtrack(vector<vector<int>>& results, int s, vector<int>& res, vector<int>& candidates, int target) {
        for (int i = s; i < candidates.size(); i++) {
            if (candidates[i] > target) return;
            else if (i && candidates[i] == candidates[i - 1] && i > s) continue; // avoid duplicate combinatiom
                                                                                 // i位置的元素与i-1的元素相同
                                                                                 // 且i-1的元素没有加入res
            else if (candidates[i] < target) {
                res.push_back(candidates[i]);
                backtrack(results, i + 1, res, candidates, target - candidates[i]);
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

int main40() {
    vector<int> candidates;
    int target;
    Solution40 solution;

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
    vector<vector<int>> results = solution.combinationSum2(candidates, target);
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