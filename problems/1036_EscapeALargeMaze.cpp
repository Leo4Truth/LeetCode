#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return bfs(blocked, source, target) && bfs(blocked, target, source);
    }

    // BFS until 
    // 1. reach the target (true) OR
    // 2. no place to go (false) OR
    // 3. get out of the max area the blocked squares can cover (true)
    // only care whether we can reach the target from the source, so no need to record path
    bool bfs(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int m = blocked.size();
        /**
         * o o o o o o o x o o o o o
         * o o o o o o x o o o o o o
         * o o o o o x o o o o o o o
         * o o o o x o o o o o o o o
         * o o o x o o o o o o o o o
         * o o x o o o o o o o o o o
         * o x o o o o o o o o o o o
         * x o o o o o o o o o o o o
         */
        int max_area = m * m / 2 + 1;

        unordered_set<int> blocked_set;
        for (int i = 0; i < m; i++) {
            int x = blocked[i][0];
            int y = blocked[i][1];
            blocked_set.insert(xy(x, y));
        }

        unordered_set<int> visited;
        visited.insert(xy(source[0], source[1]));

        queue<pair<int, int>> q;
        q.push({source[0], source[1]});

        while (!q.empty()) {
            auto [curr_x, curr_y]  = q.front();
            q.pop();
            for (auto dir : dirs) {
                int next_x = curr_x + dir[0];
                int next_y = curr_y + dir[1];
                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N 
                    || blocked_set.count(xy(next_x, next_y)) 
                    || visited.count(xy(next_x, next_y))) {
                    continue;
                }
                visited.insert(xy(next_x, next_y));
                q.push({next_x, next_y});
                // visit target or get out of the max area that m blocked squares can cover
                if (next_x == target[0] && next_y == target[1] || visited.size() > max_area) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    const int N = 1e6;
    int dirs[4][2] = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };

    /**
     * @brief turn (x, y) pair coordinate into xy single long integer index
     * 
     * @param x
     * @param y
     * @return long
     */
    long xy(long x, long y) {
        return x * N + y;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;

    return 0;
}
