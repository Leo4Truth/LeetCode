#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

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

class Solution {
public:
    virtual vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) = 0;
};

int cmp(const vector<int>& m1, const vector<int>& m2) {
    if (m1[2] > m2[2]) return 1;
    if (m1[2] < m2[2]) return -1;
    return 0;
}

class Solution_UnionFind : public Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), cmp);
        map<int, vector<vector<int>>> timeMeetingsMap;
        for (auto& meeting : meetings) {
            int time = meeting[2];
            if (timeMeetingsMap.count(time) == 0) timeMeetingsMap[time] = vector<vector<int>>();
            timeMeetingsMap[time].push_back(meeting);
        }

        UnionFind globalUF(n);
        globalUF.connect(firstPerson, 0);
        cout << globalUF.find(0) << endl;
        cout << globalUF.find(firstPerson) << endl;
        cout << "xxx" << endl;

        for (auto& entry : timeMeetingsMap) {
            // union find set of the time
            UnionFind uf(n);
            
            for (auto& meeting : entry.second) uf.connect(meeting[0], meeting[1]);

            int known = -1;
            for (auto& meeting : entry.second) {
                cout << meeting[0] << ", " << meeting[1] << endl;
                if (globalUF.find(meeting[0]) == globalUF.find(0)) {
                    known = meeting[0];
                    break;
                }
                if (globalUF.find(meeting[1]) == globalUF.find(0)) {
                    known = meeting[1];
                    break;
                }
            }

            if (known == -1) continue;
            for (auto& meeting : entry.second) {
                if (uf.find(known) == uf.find(meeting[0])) {
                    globalUF.connect(0, meeting[0]);
                    cout << "add " << meeting[0] << endl;
                }
                if (uf.find(known) == uf.find(meeting[1])) {
                    globalUF.connect(0, meeting[1]);
                    cout << "add " << meeting[1] << endl;
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (globalUF.find(i) == 0) res.push_back(i);
        }

        return res;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    int firstPerson = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> meetings;
    for (int i = 0; i < m; i++) {
        int x, y, time;
        cin >> x >> y >> time;
        meetings.push_back({x, y, time});
    }

    Solution *solution = nullptr;

    solution = new Solution_UnionFind();
    vector<int> knownPerson = solution->findAllPeople(n, meetings, firstPerson);
    cout << "[";
    for (int i = 0; i < knownPerson.size(); i++) {
        cout << knownPerson[i];
        if (i < knownPerson.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
