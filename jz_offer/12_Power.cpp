#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1.0;
        bool flag = exponent > 0;
        if (!flag) exponent = -exponent;
        for (int i = 0; i < exponent; i++) {
            if (flag) res *= base;
            else res /= base;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution solution;

    //system("pause");
    return 0;
}
