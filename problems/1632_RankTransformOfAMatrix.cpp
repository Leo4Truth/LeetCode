#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class UnionFindSet {
public:
    UnionFindSet(int n_) : n(n_), parent(vector<int>(n_)), size(vector<int>(n_, 1)) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void connect(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa == fb) return;
        if (size[fa] > size[fb]) {
            parent[fb] = fa;
            size[fa] += size[fb];
        }
        else {
            parent[fa] = fb;
            size[fb] += size[fa];
        }
    }
    
private:
    int n;
    vector<int> parent, size;
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};

        UnionFindSet ufs(m * n);
        for (int i = 0; i < m; i++) {
            map<int, vector<int>> mp;
            for (int j = 0; j < n; j++) {
                mp[matrix[i][j]].emplace_back(i * n + j);
            }
            for (auto &[num, vec] : mp) {
                for (int k = 0; k < vec.size() - 1; k++) {
                    ufs.connect(vec[k], vec[k + 1]);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            map<int, vector<int>> mp;
            for (int i = 0; i < m; i++) {
                mp[matrix[i][j]].emplace_back(i * n + j);
            }
            for (auto &[num, vec] : mp) {
                for (int k = 0; k < vec.size() - 1; k++) {
                    ufs.connect(vec[k], vec[k + 1]);
                }
            }
        }

        vector<vector<int>> adj(m * n);
        vector<int> indegree(m * n);
        for (int i = 0; i < m; i++) {
            vector<pair<int, int>> v(n);
            for (int j = 0; j < n; j++) {
                v[j] = make_pair(matrix[i][j], j);
            }
            sort(v.begin(), v.end());
            for (int j = 0; j < n - 1; j++) {
                if (v[j].first != v[j + 1].first) {
                    int uu = ufs.find(i * n + v[j].second);
                    int vv = ufs.find(i * n + v[j + 1].second);
                    adj[uu].emplace_back(vv);
                    indegree[vv]++;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            vector<pair<int, int>> v(m);
            for (int i = 0; i < m; i++) {
                v[i] = make_pair(matrix[i][j], i);
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < m - 1; i++) {   
                if (v[i].first != v[i + 1].first) {
                    int uu = ufs.find(v[i].second * n + j);
                    int vv = ufs.find(v[i + 1].second * n + j);
                    adj[uu].emplace_back(vv);
                    indegree[vv]++;
                }
            }
        }

        vector<int> resVec(m * n, 1);
        queue<int> q;
        for (int t = 0; t < m * n; t++) {
            if (ufs.find(t) == t && indegree[t] == 0) {
                q.emplace(t);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                resVec[v] = resVec[v] > (resVec[u] + 1) ? resVec[v] : (resVec[u] + 1);
                indegree[v]--;
                if (indegree[v] == 0) q.emplace(v);
            }
        }
        vector<vector<int>> resMat(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                resMat[i][j] = resVec[ufs.find(i * n + j)];
            }
        }
        return resMat;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }

    Solution solution;
    vector<vector<int>> res = solution.matrixRankTransform(matrix);
    for (auto row : res) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    //system("pause");
    return 0;
}
