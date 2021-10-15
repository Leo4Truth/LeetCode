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
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> gene2index;
        for (int i = 0; i < bank.size(); i++) gene2index[bank[i]] = i;
        
        int startIdx = bank.size();
        int endIdx = bank.size() + 1;
        if (gene2index.count(start) == 0) {
            bank.push_back(start);
            gene2index[start] = bank.size();
        }
        else startIdx = gene2index[start];
        if (gene2index.count(end) == 0) return -1;
        else endIdx = gene2index[end];

        vector<vector<int>> adjMatrix(bank.size(), vector<int>(bank.size(), 0));
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                if (distance(bank[i], bank[j]) == 1) {
                    adjMatrix[i][j] = 1;
                    adjMatrix[j][i] = 1;
                }
            }
        }

#ifdef DEBUG
        for (int i = 0; i < bank.size(); i++) {
            cout << bank[i] << " " << i << ": ";
            for (int j = 0; j < bank.size(); j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
#endif // DEBUG

        vector<bool> visited(bank.size(), false);
        visited[startIdx] = true;
        queue<int> q;
        queue<int> qDis;
        q.push(startIdx);
        qDis.push(0);
        while (!q.empty()) {
            int cur = q.front();
            int curDis = qDis.front();
            q.pop();
            qDis.pop();
            for (int next = 0; next < bank.size(); next++) {
                if (!visited[next] && adjMatrix[cur][next] == 1) {
                    if (next == endIdx) return curDis + 1;
                    q.push(next);
                    qDis.push(curDis + 1);
                }
            }
        }

        return -1;
    }

private:
    int distance(string s1, string s2) {
        if (s1.size() != s2.size()) return -1;
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) cnt += (s1[i] != s2[i]);
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string start = argc >= 3 ? argv[2] : "";
    string end = argc >= 4 ? argv[3] : "";
    vector<string> bank;
    for (int i = 0; i < n; i++) {
        string gene;
        cin >> gene;
        bank.push_back(gene);
    }

    Solution solution;
    cout << solution.minMutation(start, end, bank) << endl;
    
    return 0;
}
