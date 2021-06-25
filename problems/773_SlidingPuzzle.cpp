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
    // bfs
    // pass
    // Time:  16 ms, defeat 35.84%
    // Space: 9.8 MB, defeat 28.32%
    int slidingPuzzle_bfs(vector<vector<int>>& board) {
        // initial status
        string initial;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                initial += char(board[i][j] + '0');
            }
        }
        if (initial == "123450") {
            return 0;
        }

        queue<pair<string, int>> q;
        q.emplace(initial, 0);
        unordered_set<string> seen = {initial};

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (auto&& next_status: getAllNextStatus(status)) {
                if (!seen.count(next_status)) {
                    if (next_status == "123450") {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }

    vector<string> getAllNextStatus(string& status) {
        vector<string> allNextStatus;
        int idx = status.find('0');
        for (auto neighbor : neighbors[idx]) {
            swap(status, idx, neighbor);
            allNextStatus.push_back(status);
            swap(status, idx, neighbor);
        }
        return allNextStatus;
    }

    void swap(string& status, int x, int y) {
        char tmp = status[x];
        status[x] = status[y];
        status[y] = tmp;
    }

private:
    const int m = 2;
    const int n = 3;
    vector<vector<int>> neighbors{
        {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}
    };
};

int main(int argc, char* argv[]) {

    Solution solution;

    //system("pause");
    return 0;
}
