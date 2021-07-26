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
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        if (n == 0) return {};
        vector<int> array;
        unordered_map<int, vector<int>> hashmap;
        for (auto adjacentPair : adjacentPairs) {
            hashmap[adjacentPair[0]].push_back(adjacentPair[1]);
            hashmap[adjacentPair[1]].push_back(adjacentPair[0]);
        }
        int s = 100001; // start
        for (auto entry : hashmap) {
            if (entry.second.size() == 1) {
                s = entry.first;
                break;
            }
        }
        if (s == 100001) return {};
        array.push_back(s);
        array.push_back(hashmap[s][0]);
        for (int i = 2; i < n + 1; i++) {
            int curr = array.back();
            int next = array[i - 2] == hashmap[curr][0] ? hashmap[curr][1] : hashmap[curr][0];
            array.push_back(next);
        }
        return array;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> adjacentPairs;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adjacentPairs.push_back({x, y});
    }

    Solution solution;
    vector<int> array = solution.restoreArray(adjacentPairs);
    for (auto x : array) cout << x << " ";
    cout << endl;

    //system("pause");
    return 0;
}
