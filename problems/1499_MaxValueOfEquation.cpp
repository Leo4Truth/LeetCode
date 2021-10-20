#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        if (n == 0 || n == 1) return 0;
        int max = INT32_MIN;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = abs(points[i][0] - points[j][0]) <= k
                if (dx) {
                    if ()
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {

    Solution solution;

    //system("pause");
    return 0;
}
