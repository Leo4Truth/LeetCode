#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0 || number == 1) return 1;
        return int(pow(2, number - 1));
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;

    Solution solution;
    cout << solution.jumpFloorII(n) << endl;

    //system("pause");
    return 0;
}
