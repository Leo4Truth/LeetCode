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
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1, s2, s3;
        s1 = (ay2 - ay1) * (ax2 - ax1); 
        s2 = (by2 - by1) * (bx2 - bx1);
        int x, y;
        x = max(0, min(ax2, bx2) - max(ax1, bx1)); 
        y = max(0, min(ay2, by2) - max(ay1, by1));
        s3 = x * y;
        return s1 + s2 - s3;
    }

    int computeArea_1(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a_l = ax2 - ax1;
        int a_w = ay2 - ay1;
        int b_l = bx2 - bx1;
        int b_w = by2 - by1;
        int area_a = a_l * a_w;
        int area_b = b_l * b_w;
        int area_sum = area_a + area_b;
        int area_overlap = 0;
        int l_overlap = 0;
        int w_overlap = 0;
        if (ax1 >= bx2) return area_sum;
        else if (ax2 <= bx1) return area_sum;
        else if (ay1 >= by2) return area_sum;
        else if (ay2 <= by1) return area_sum;
        else if (ax1 <= bx1 && bx2 <= ax2 && ay1 <= by1 && by2 <= ay2) return area_a;
        else if (bx1 <= ax1 && ax2 <= bx2 && by1 <= ay1 && ay2 <= by2) return area_b;

        if (ax1 <= bx1 && ax2 <= bx2) l_overlap = ax2 - bx1;
        else if (bx1 <= ax1 && bx2 <= ax2) l_overlap = bx2 - ax1;
        else if (ax1 <= bx1 && bx2 <= ax2) l_overlap = b_l;
        else if (bx1 <= ax1 && ax2 <= bx2) l_overlap = a_l;

        if (ay1 <= by1 && ay2 <= by2) w_overlap = ay2 - by1;
        else if (by1 <= ay1 && by2 <= ay2) w_overlap = by2 - ay1;
        else if (ay1 <= by1 && by2 <= ay2) w_overlap = b_w;
        else if (by1 <= ay1 && ay2 <= by2) w_overlap = a_w;

        area_overlap = l_overlap * w_overlap;
        return area_sum - area_overlap;
    }
};

int main(int argc, char* argv[]) {
    int ax1 = argc >= 2 ? stoi(argv[1]) : 0;
    int ay1 = argc >= 3 ? stoi(argv[2]) : 0;
    int ax2 = argc >= 4 ? stoi(argv[3]) : 0;
    int ay2 = argc >= 5 ? stoi(argv[4]) : 0;
    int bx1 = argc >= 6 ? stoi(argv[5]) : 0;
    int by1 = argc >= 7 ? stoi(argv[6]) : 0;
    int bx2 = argc >= 8 ? stoi(argv[7]) : 0;
    int by2 = argc >= 9 ? stoi(argv[8]) : 0;

    Solution solution;
    cout << solution.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;

    return 0;
}
