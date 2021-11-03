#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    virtual int trapRainWater(vector<vector<int>>& heightMap) = 0;
};

/**
 * @brief min heap, Dijkstra Shortest Path with Heap optimization indeed
 * Time Complexity: O(mnlog(m+n))
 * Space Complexity: O(mn)
 */
class Solution_minHeap : public Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m <= 2) return 0;
        int n = heightMap[0].size();
        if (n <= 2) return 0;

        // 方块接水后的高度 = max(方块的高度, min(方块四周相邻方块的高度))
        // water[i][j] = max(heightMap[i][j], min(heightMap[i - 1][j], heightMap[i][j - 1], heightMap[i + 1][j], heightMap[i][j + 1]))
        vector<vector<int>> water(heightMap);

        // 优先队列, 存储 <方块高度: heightMap[i][j], 方块index: i * n + j>, 按方块高度升序排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        // 先处理最外层一圈, 都接不住雨水
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i * n + j});
                    visit[i][j] = true;
                }
            }
        }

        int sum = 0;
        int dirs[] = {-1, 0, 1, 0, -1}; // tricky
        while (!pq.empty()) {
            // 从优先队列队首弹出的是所有已访问方块中高度最低的
            auto curr = pq.top();
            pq.pop();
            // 检查4个方向的相邻方块
            for (int k = 0; k < 4; k++) {
                int nx = curr.second / n + dirs[k];
                int ny = curr.second % n + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    // 如果当前方块(已访问方块中高度最低)高度高于相邻方块, 则相邻方块的可积水量为两方块高度差
                    if (heightMap[nx][ny] < curr.first) {
                        sum += curr.first - heightMap[nx][ny]; 
                    }
                    visit[nx][ny] = true;
                    // 当前方块和相邻方块中取较高的放入优先队列
                    pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
                }
            }
        }
        
        return sum;
    }
};

/**
 * @brief BFS, Bellman-Ford Shortest Path indeed
 * Time Complexity: O(m^2*n^2)
 * Space Complexity: O(mn)
 */
class Solution_bfs : public Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m <= 2) return 0;
        int n = heightMap[0].size();
        if (n <= 2) return 0;

        // TODO

        return 0;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> heightMap;
    for (int i = 0; i < m; i++) {
        vector<int> heightRow;
        for (int j = 0; j < n; j++) {
            int height;
            cin >> height;
            heightRow.push_back(height);
        }
        heightMap.push_back(heightRow);
    }

    Solution *solution = new Solution_minHeap();
    cout << solution->trapRainWater(heightMap) << endl;

    return 0;

}
