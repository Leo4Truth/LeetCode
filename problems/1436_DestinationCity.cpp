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
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> map;
        for (auto path : paths) {
            if (map.count(path[1]) == 0 || map[path[1]] == 0) map[path[1]] = 1;
            if (map.count(path[0]) == 0 || map[path[0]] == 0 || map[path[0]] == 1) map[path[0]] = 2;
        }

        for (auto entry : map) {
            if (map[entry.first] == 1) return entry.first;
        }

        return "";
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<string>> paths;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        paths.push_back({a, b});
    }

    Solution solution;
    cout << solution.destCity(paths) << endl;
    
    return 0;
}
