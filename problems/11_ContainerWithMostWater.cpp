#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;

        int max_area = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            max_area = max(h * (r - l), max_area);
            while (height[l] <= h && l < r) l++;
            while (height[r] <= h && l < r) r--;
        }
        return max_area;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> height;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        height.push_back(h);
    }
    Solution11 solution;
    cout << solution.maxArea(height) << endl;

    //system("pause");
    return 0;
}

