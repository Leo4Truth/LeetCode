#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int n1 = 1, n2 = 2, n3;
        for (int i = 3; i <= number; i++) {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;

    Solution solution;
    cout << solution.jumpFloor(n) << endl;

    //system("pause");
    return 0;
}
