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
    int add(int a, int b) {
        // 后续用a表示非进位和，b表示进位，当进位为0，则表示计算结束
        return b == 0 ? a : add(a ^ b, (unsigned int)(a & b) << 1);
    }

    int add_java(int a, int b) {
        while (b != 0) { // 当进位为 0 时跳出
            int c = (a & b) << 1;  // c = 进位
            a ^= b; // a = 非进位和
            b = c; // b = 进位
        }
        return a;
    }
};

int main(int argc, char* argv[]) {
    int a = argc >= 2 ? stoi(argv[1]) : 0;
    int b = argc >= 3 ? stoi(argv[2]) : 0;

    Solution solution;
    cout << solution.add(a, b) << endl;

    return 0;
}
