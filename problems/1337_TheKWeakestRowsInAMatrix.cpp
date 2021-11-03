#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    // 0: index, 1: cnt
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
};

class Solution1337 {
public:
    // sorted hashmap by key
    vector<int> kWeakestRows_hashmap(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();
        if (n == 0) return {};
        
        // STL map sorted by key
        map<int, vector<int>> map;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) cnt++;
                else break;
            }
            if (map.count(cnt) > 0) map[cnt].push_back(i);
            else map[cnt] = {i};
        }

        vector<int> res;
        int kk = 0;
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) {
                res.push_back(map[i][j]);
                kk++;
                if (kk == k) return res;
            }
        }
        return res;
    }

    vector<int> kWeakestRows_sort(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();
        if (n == 0) return {};
        
        vector<vector<int>> sorted;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) cnt++;
                else break;
            }
            sorted.push_back({i, cnt});
        }
        
        sort(sorted.begin(),sorted.end(),cmp);

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(sorted[i][0]);
        }
        return res;
    }

    // Stupid but passed
    vector<int> kWeakestRows_2(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();
        if (n == 0) return {};
        cout << "m: " << m << ", n: " << n << endl;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j];
                if (j < mat[i].size() - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        unordered_map<int, int> map; // key: cnt, value: pos in order.
        vector<int> count;
        vector<int> order;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < mat[i].size(); j++) cnt += mat[i][j];
            count.push_back(cnt);
            cout << "row: " << i << ", count: " << cnt << endl;
            if (map.find(cnt) != map.end()) {
                cout << cnt << " found, insert into pos: " << map[cnt] + 1 << endl;
                order.insert(order.begin() + map[cnt] + 1, i);
                map[cnt] += 1;
                for (auto it : map) {
                    cout << "count: " << it.first;
                    if (it.first > cnt) {
                        map[it.first]++;
                        cout << "++";
                    }
                    cout << endl;
                }
            }
            else {
                cout << cnt << " not found, insert into pos: ";
                bool flag = false;
                for (int pos = 0; pos < order.size(); pos++) {
                    if (count[order[pos]] > cnt) {
                        cout << pos << " (not last)" << endl;
                        order.insert(order.begin() + pos, i);
                        map[cnt] = pos;
                        flag = true;
                        for (auto it : map) {
                            cout << "count: " << it.first;
                            if (it.first > cnt) {
                                map[it.first]++;
                                cout << "++";
                            }
                            cout << endl;
                        }
                        break;
                    }
                }
                if (!flag) {
                    cout << order.size() << " (last)" << endl;
                    order.push_back(i);
                    map[cnt] = order.size() - 1;
                    flag = true;
                }
            }

            cout << "map:" << endl;
            for (auto it : map) cout << it.first << ": " << it.second << endl;
            cout << "order:" << endl;
            for (int j = 0; j < order.size(); j++) cout << j << ": " << order[j] << endl;
        }

        cout << "calculating result..." << endl;
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(order[i]);
        return res;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 5;
    int n = argc >= 3 ? stoi(argv[2]) : 5;
    int k = argc >= 4 ? stoi(argv[3]) : 3;
    vector<vector<int>> mat;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        mat.push_back(row);
    }

    Solution1337 solution;
    vector<int> res = solution.kWeakestRows_hashmap(mat, k);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}

