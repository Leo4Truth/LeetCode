#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution149 {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<long double, int> map;
            int same = 1;
            int localmax = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0]) {
                    if (points[i][1] == points[j][1]) same++;
                    else map[INT32_MAX]++;
                }
                else {
                    long double slope = (long double)(points[i][1] - points[j][1])/(long double)(points[i][0] - points[j][0]);
                    map[slope]++; 
                }
            }
            for (auto it : map) localmax = max(localmax, it.second);
            localmax += same;
            res = max(res, localmax);
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 3;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    
    Solution149 solution;
    cout << solution.maxPoints(points) << endl;

    //system("pause");
    return 0;
}

