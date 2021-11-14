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

class Solution {
public:
    virtual vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) = 0;
};

class UnionFind {
    int n;
    vector<int> parent, size;

public:
    UnionFind(int n) {
        this->n = n;
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; ++i)
        parent[i] = i;
    }
    
    int find(int idx) {
        if (parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    
    void connect(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) {
            if (size[fa] > size[fb]) {
                parent[fb] = fa;
                size[fa] += size[fb];
            }
            else {
                parent[fa] = fb;
                size[fb] += size[fa];
            }
        }
    }
};

class Solution_UnionFind : public Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        
        UnionFind uf(n);
        
        for (auto &req : requests) {
            int u = req[0], v = req[1];
            if (uf.find(u) == uf.find(v))
                ans.push_back(true);
            else {
                bool valid = true;
                for (auto &res : restrictions) {
                    int p = res[0], q = res[1];
                    if ((uf.find(u) == uf.find(p) && uf.find(v) == uf.find(q))
                        || (uf.find(u) == uf.find(q) && uf.find(v) == uf.find(p))) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    uf.connect(u, v);
                    ans.push_back(true);
                } else
                    ans.push_back(false);
            }
        }
        
        return ans;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    int k = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> restrictions;
    vector<vector<int>> requests;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        restrictions.push_back({x, y});
    }
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        requests.push_back({u, v});
    }

    Solution *solution = nullptr;

    solution = new Solution_UnionFind();
    vector<bool> results = solution->friendRequests(n, restrictions, requests);

    cout << "[";
    for (int i = 0; i < k; i++) {
        cout << results[i];
        if (i < k - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
