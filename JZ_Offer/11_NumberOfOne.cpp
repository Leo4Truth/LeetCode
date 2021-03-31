#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 10;

    Solution solution;
    cout << solution.NumberOf1(n) << endl;

    //system("pause");
    return 0;
}
