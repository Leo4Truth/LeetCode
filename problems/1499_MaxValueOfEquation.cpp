#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
    bool operator<(const Point &other) const {
        return (y - x) < (other.y - other.x);
    }
    int operator-(const Point &other) const {
        return y + other.y + other.x - x;
    }
    Point(const vector<int>& p): x(p[0]), y(p[1]) {}
};

class Solution {
public:
    // priority queue
    // max(yi + yj + |xi - xj|) = max(yi + yj + xj - xi) = max(xj + yj) - min(xi - yi)
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<Point> pq;
        int res = INT32_MIN;
        for (auto &p: points) {
            Point po(p);
            while (pq.size() && (po.x - pq.top().x > k)) pq.pop();
            if (pq.size()) res = std::max(res, pq.top() - po);
            pq.push(po);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    Solution solution;
    cout << solution.findMaxValueOfEquation(points, k) << endl;
    
    return 0;
}
