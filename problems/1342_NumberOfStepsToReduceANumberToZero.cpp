#include <iostream>
#include <vector>

using namespace std;

class Solution1342 {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        while (num != 0) {
            if (num % 2 == 0) num /= 2;
            else num -= 1;
            steps++;
        }
        return steps;
    }
};

int main(int argc, char* argv[]) {
    int num = argc >= 2 ? stoi(argv[1]) : 14;

    Solution1342 solution;
    cout << solution.numberOfSteps(num) << endl;

    //system("pause");
    return 0;
}
