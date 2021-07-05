#include <iostream>
#include <string>
#include <algorithm> // reverse()

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = i >= 0 ? (int)(num1[i] - '0') : 0;
            int d2 = j >= 0 ? (int)(num2[j] - '0') : 0;
            int d = d1 + d2 + carry;
            carry = d / 10;
            d = d % 10;
            i--;
            j--;
            sum.insert(0, 1, (char)(d + '0'));
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    string num1 = argc >= 2 ? argv[1] : "101";
    string num2 = argc >= 3 ? argv[2] : "99";

    Solution solution;
    cout << solution.addStrings(num1, num2) << endl;

    //system("pause");
    return 0;
}
