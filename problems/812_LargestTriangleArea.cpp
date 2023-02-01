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

class Solution {
public:
    virtual double largestTriangleArea(vector<vector<int>>& points) = 0;
};

/**
 * @brief Heron's Formual to calculate area of triangle, traverse all possible triangles
 * S = sqrt(p * (p - a) * (p - b) * (p - c)) where p = (a + b + c) / 2
 * Time Complexity: O(N^3)
 * Space Complexity: O(1)
 */
class Solution_Heron : public Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return 0.0;
        double largest = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double a = len(points[i], points[j]);
                    double b = len(points[j], points[k]);
                    double c = len(points[k], points[i]);
                    double area = areaHeron(a, b, c);
                    largest = area > largest ? area : largest;
                }
            }
        }
        return largest;
    }

private:
    double len(vector<int>& p1, vector<int>& p2) {
        return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
    }

    double areaHeron(double a, double b, double c) {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

/**
 * @brief Convex Hull & Andrew
 * Time Complexity: O(N^2)
 * Space Complexity: O(N)
 */
class Solution_Andrew : public Solution {
public:
    double largestTriangleArea(vector<vector<int>> & points) {
        auto convexHull = getConvexHull(points);
        int n = convexHull.size();
        double ret = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = i + 2; j + 1 < n; j++) {
                while (k + 1 < n) {
                    double curArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                    double nextArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k + 1][0], convexHull[k + 1][1]);
                    if (curArea >= nextArea) {
                        break;
                    }
                    k++;
                }
                double area = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                ret = max(ret, area);
            }
        }
        return ret;
    }

private:
    int cross(const vector<int> & p, const vector<int> & q, const vector<int> & r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> getConvexHull(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) {
            return points;
        }
        /* 按照 x 大小进行排序，如果 x 相同，则按照 y 的大小进行排序 */
        sort(points.begin(), points.end(), [](const vector<int> & a, const vector<int> & b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> hull;
        /* 求出凸包的下半部分 */
        for (int i = 0; i < n; i++) {
            while (hull.size() > 1 && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        int m = hull.size();
        /* 求出凸包的上半部分 */
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > m && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        /* hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0] */
        hull.pop_back();
        return hull;
    }

    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }
};


int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    Solution *solution = nullptr;

    solution = new Solution_Heron();
    cout << "Heron : " << solution->largestTriangleArea(points) << endl;

    solution = new Solution_Andrew();
    cout << "Andrew: " << solution->largestTriangleArea(points) << endl;

    return 0;
}
