#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    virtual vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) = 0;
};

class Solution_dfs : public Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
    }

private:
    
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int e = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    Solution *solution = nullptr;

    cout << "dfs: [";
    solution = new Solution_dfs();
    vector<int> mins = solution->findMinHeightTrees(n, edges);
    for (int i = 0; i < mins.size(); i++) {
        cout << mins[i];
        if (i < mins.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
