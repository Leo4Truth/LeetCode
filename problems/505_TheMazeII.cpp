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
    // Time Complexity:  O(m*n*max(m, n))
    // Space Complexity: O(m*n)
    int shortestDistance_bfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (m == 0) return -1;
        int n = maze[0].size();
        if (n == 0) return -1;
        vector<vector<int>> distance(m, vector<int>(n, INT32_MAX));
        distance[start[0]][start[1]] = 0;
        vector<vector<int>> dirs = {{0, 1} ,{0, -1}, {-1, 0}, {1, 0}};
        queue<vector<int>> q;
        q.push(start);
        while (!q.empty()) {
            vector<int> p = q.front();
            q.pop();
            for (auto dir : dirs) {
                int x = p[0] + dir[0];
                int y = p[1] + dir[1];
                int cnt = 0;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    cnt++;
                }
                x -= dir[0];
                y -= dir[1];
                if (distance[p[0]][p[1]] + cnt < distance[x][y]) {
                    distance[x][y] = distance[p[0]][p[1]] + cnt;
                    q.push({x, y});
                }
            }
        }
        if (distance[destination[0]][destination[1]] == INT32_MAX) return -1;
        return distance[destination[0]][destination[1]];
    }

    int shortestDistance_dijkstra_priority_queue(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (m == 0) return -1;
        int n = maze[0].size();
        if (n == 0) return -1;
        vector<vector<int>> distance(m, vector<int>(n, INT32_MAX));
        distance[start[0]][start[1]] = 0;
        dijkstra_priority_queue(maze, start, distance);
        return distance[destination[0]][destination[1]] == INT32_MAX ? -1 : distance[destination[0]][destination[1]];
    }

private:
    struct cmp {
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[2] - b[2];
        }
    };

    void dijkstra_priority_queue(vector<vector<int>>& maze, vector<int>& start, vector<vector<int>>& distance) {
        int m = maze.size();
        if (m == 0) return;
        int n = maze[0].size();
        if (n == 0) return;
        vector<vector<int>> dirs = {{0, 1} ,{0, -1}, {-1, 0}, {1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        pq.push({start[0], start[1], 0});
        while (!pq.empty()) {
            vector<int> s = pq.top();
            if (distance[s[0]][s[1]] < s[2]) continue;
            for (auto dir : dirs) {
                int x = s[0] + dir[0];
                int y = s[1] + dir[1];
                int cnt = 0;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    cnt++;
                }
                x -= dir[0];
                y -= dir[1];
                if (distance[s[0]][s[1]] + cnt < distance[x][y]) {
                    distance[x][y] = distance[s[0]][s[1]] + cnt;
                    pq.push({x, y, distance[x][y]});
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 4;
    int n = argc >= 3 ? stoi(argv[2]) : 4;
    vector<vector<int>> maze;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x != 0 && x != 1) return -1;
            row.push_back(x);
        }
        maze.push_back(row);
    }
    vector<int> start;
    vector<int> destination;
    int x, y;
    cin >> x >> y;
    start.push_back(x);
    start.push_back(y);
    cin >> x >> y;
    destination.push_back(x);
    destination.push_back(y);

    Solution solution;
    cout << solution.shortestDistance_dijkstra_priority_queue(maze, start, destination) << endl;

    //system("pause");
    return 0;
}
