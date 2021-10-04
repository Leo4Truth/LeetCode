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
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string decimal = "";
        if (numerator < 0 ^ denominator < 0) decimal.append("-");
        long dividend = abs(numerator);
        long divisor = abs(denominator);
        decimal.append(to_string(dividend / divisor));
        long remainder = dividend % divisor;
        if (remainder == 0) return decimal;
        decimal.append(".");
        unordered_map<long, int> map;
        while (remainder != 0) {
            if (map.count(remainder) != 0 && map[remainder] != 0) {
                decimal.insert(map[remainder], "(");
                decimal.append(")");
                return decimal;
            }
            map[remainder] = decimal.length();
            remainder *= 10;
            decimal.append(to_string(remainder / divisor));
            remainder %= divisor;
        }
        return decimal;
    }

    string fractionToDecimal_0(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string fraction = "";
        if (numerator < 0 ^ denominator < 0) fraction.append("-");
        long dividend = abs(numerator);
        long divisor = abs(denominator);
        fraction.append(to_string(dividend / divisor));
        long remainder = dividend % divisor;
        if (remainder == 0) return fraction;
        fraction.append(".");
        unordered_map<long, int> map;
        while (remainder != 0) {
            if (map.count(remainder) != 0 && map[remainder] != 0) {
                fraction.insert(map[remainder], "(");
                fraction.append(")");
                return fraction;
            }
            map[remainder] = fraction.length();
            remainder *= 10;
            fraction.append(to_string(remainder / divisor));
            remainder %= divisor;
        }
        return fraction;
    }
};

int main(int argc, char* argv[]) {
    int numerator = argc >= 2 ? stoi(argv[1]) : 0;
    int denomitor = argc >= 3 ? stoi(argv[2]) : 0;

    Solution solution;
    cout << solution.fractionToDecimal(numerator, denomitor) << endl;

    //system("pause");
    return 0;
}
