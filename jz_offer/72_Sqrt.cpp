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
    int mySqrt(int x) {
        long l = 1, r = x;
        long mid = (l + r) / 2;
        while (l <= r) {
            if ((mid * mid <= x) && ((mid + 1) * (mid + 1) > x)) return mid;
            else if (mid * mid > x) r = mid;
            else if ((mid + 1) * (mid + 1) < x) l = mid;
            else if ((mid + 1) * (mid + 1) == x) return mid + 1;
            mid = (l + r) / 2;
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    int x = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.mySqrt(x) << endl;

    //system("pause");
    return 0;
}
