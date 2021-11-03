#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution991 {
public:
    int brokenCalc(int X, int Y) {
        if (X == Y) return 0;
        int res = 0;
        while (Y > X) {
            if (Y % 2 == 1) Y++;
            else Y /= 2;
            res++;
        }
        return res + X - Y;
    }
};

int main(int argc, char* argv[]) {
    int X = argc >= 2 ? stoi(argv[1]) : 0;
    int Y = argc >= 3 ? stoi(argv[2]) : 0;

    Solution991 solution;
    cout << solution.brokenCalc(X, Y) << endl;

    //system("pause");
    return 0;
}

