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
    virtual vector<vector<string>> groupAnagrams(vector<string>& strs) = 0;
};

class Solution_sort_hash : public Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto str : strs) {
            string str_copy(str);
            sort(str_copy.begin(), str_copy.end());
            if (map.count(str_copy) == 0) map[str_copy] = {str};
            else map[str_copy].push_back(str);
        }
        vector<vector<string>> res;
        for (auto &entry : map) res.push_back(entry.second);
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    cout << n << endl;
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    Solution *solution = nullptr;

    solution = new Solution_sort_hash();
    vector<vector<string>> res = solution->groupAnagrams(strs);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "  [";
        for (int j = 0; j < res[i].size(); j++) {
            cout << "\"" << res[i][j] << "\"";
            if (j < res[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < res.size() - 1) cout << ",";
        cout << endl;
    }
    cout << "]" << endl;
    
    return 0;
}
