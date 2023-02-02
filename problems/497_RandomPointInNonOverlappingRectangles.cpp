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

/**
 * @brief 水塘采样
 * 水塘面积不一样, 每个水塘被选中的概率与其面积成正比
 */
class Solution {
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        srand((unsigned int) time(nullptr));
    }
    
    vector<int> pick() {
        int total_area = 0;
        vector<int> r;
        for (auto& rect : rects) {
            int rect_area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            total_area += rect_area;
            if (rand() % total_area < rect_area) r = rect;
        }
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return {x, y};
    }

private:
    vector<vector<int>>& rects;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> rects;
    for (int i = 0; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        rects.push_back({a, b, x, y});
    }

    Solution *solution = nullptr;

    solution = new Solution(rects);
    vector<int> uv = solution->pick();
    cout << "(" << uv[0] << ", " << uv[1] << ")" << endl;

    return 0;
}
