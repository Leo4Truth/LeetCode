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
    int Fibonacci(int n) {
        if (n == 0) return 0;
        int f0 = 0, f1 = 1, f2 = 1;
        for (int i = 1; i < n; i++) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.Fibonacci(n) << endl;

    //system("pause");
    return 0;
}

