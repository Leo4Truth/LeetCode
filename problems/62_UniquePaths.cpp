#include <iostream>
#include <vector>

using namespace std;

class Solution62 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        long int res = 1;
        int a = m + n - 2;
        int b = m < n ? m - 1 : n - 1;
        for (int i = 0; i < b; i++) {
            res *= a - i;
        }
        for (int i = b; i >= 2; i--) {
            res /= i;
        }
        return res;
    }
};

int main62() {
    Solution62 solution;
    int m, n;
    cin >> m >> n;
    cout << solution.uniquePaths(m, n) << endl;
    system("pause");
    return 0;
}