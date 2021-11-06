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
    virtual vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) = 0;
};

class Solution_init : public Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        return 0;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    Solution *solution = nullptr;

    solution = new Solution_init();

    return 0;
}
