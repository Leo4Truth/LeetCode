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
    virtual bool isRectangleCover(vector<vector<int>>& rectangles)= 0;
};

// self define hash to speed up
namespace std {
    template<> struct hash<pair<int, int>> {
        inline size_t operator()(const pair<int, int> v) const {
            hash<int> h;
            return (h(v.first) << 32) + h(v.second);
        }
    };
}

typedef pair<int, int> point;

class Solution_hash : public Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long area = 0;
        int minX = rectangles[0][0], minY = rectangles[0][1], maxX = rectangles[0][2], maxY = rectangles[0][3];
        unordered_map<point, int> cnt;
        for (auto & rect : rectangles) {
            int x = rect[0], y = rect[1], a = rect[2], b = rect[3];
            area += (long) (a - x) * (b - y);

            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, a);
            maxY = max(maxY, b);

            point point1({x, y});
            point point2({x, b});
            point point3({a, y});
            point point4({a, b});

            cnt[point1] += 1;
            cnt[point2] += 1;
            cnt[point3] += 1;
            cnt[point4] += 1;
        }

        point pointMinMin({minX, minY});
        point pointMinMax({minX, maxY});
        point pointMaxMin({maxX, minY});
        point pointMaxMax({maxX, maxY});
        if (area != (long long) (maxX - minX) * (maxY - minY) 
        || !cnt.count(pointMinMin) || !cnt.count(pointMinMax) 
        || !cnt.count(pointMaxMin) || !cnt.count(pointMaxMax)) {
            return false;
        }

        cnt.erase(pointMinMin);
        cnt.erase(pointMinMax);
        cnt.erase(pointMaxMin);
        cnt.erase(pointMaxMax);

        for (auto & entry : cnt) {
            int value = entry.second;
            if (value != 2 && value != 4) {
                return false;
            }
        }

        return true;
    }

private:
};

class Solution_set : public Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        if (n == 0) return false;
        if (n == 1) return true;

        unordered_set<string> set;
        
        int left = INT32_MAX;
        int right = INT32_MIN;
        int top = INT32_MIN;
        int bottom = INT32_MAX;
        int sum = 0;
        for (auto& rectangle : rectangles) {
            left = rectangle[0] < left ? rectangle[0] : left;
            bottom = rectangle[1] < bottom ? rectangle[1] : bottom;
            right = rectangle[2] > right ? rectangle[2] : right;
            top = rectangle[3] > top ? rectangle[3] : top;

            sum += (rectangle[3] - rectangle[1]) * (rectangle[2] - rectangle[0]);

            //分别记录小矩形的坐标
            string lt = to_string(rectangle[0]) + " " + to_string(rectangle[3]);
            string lb = to_string(rectangle[0]) + " " + to_string(rectangle[1]);
            string rt = to_string(rectangle[2]) + " " + to_string(rectangle[3]);
            string rb = to_string(rectangle[2]) + " " + to_string(rectangle[1]);
            
            //如果有就移除 没有就加入
            if (!set.count(lt)) set.insert(lt);
            else set.erase(lt);
            if (!set.count(lb)) set.insert(lb);
            else set.erase(lb);
            if (!set.count(rt)) set.insert(rt);
            else set.erase(rt);
            if (!set.count(rb)) set.insert(rb);
            else set.erase(rb);
        }

        if (set.size() == 4 
        && set.count(to_string(left) + " " + to_string(top))
        && set.count(to_string(right) + " " + to_string(top))
        && set.count(to_string(left) + " " + to_string(bottom))
        && set.count(to_string(right) + " " + to_string(bottom))) {
            return sum == (right - left) * (top - bottom);
        }

        return false;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> rectangles;
    for (int i = 0; i < n; i++) {
        int left;
        int bottom;
        int right;
        int top;
        cin >> left >> bottom >> right >> top;
        rectangles.push_back({left, bottom, right, top});
    }

    Solution *solution = nullptr;

    solution = new Solution_set();
    cout << "set : " << solution->isRectangleCover(rectangles) << endl;

    solution = new Solution_hash();
    cout << "hash: " << solution->isRectangleCover(rectangles) << endl;

    return 0;
}
