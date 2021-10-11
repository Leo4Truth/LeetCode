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
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string num_str = "";
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            int cur_num = num / unit;
            if (cur_num != 0) {
                num -= cur_num * unit;
                num_str = num_str + toEnglish(cur_num) + thousands[i] + " ";
            }
        }

        while (num_str.back() == ' ') num_str.pop_back();
        return num_str;
    }

private:
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string toEnglish(int num) {
        string curr;
        int hundred = num / 100;
        num %= 100;
        if (hundred != 0) {
            curr = curr + singles[hundred] + " Hundred ";
        }
        int ten = num / 10;
        if (ten >= 2) {
            curr = curr + tens[ten] + " ";
            num %= 10;
        }
        if (num > 0 && num < 10) {
            curr = curr + singles[num] + " ";
        } else if (num >= 10) {
            curr = curr + teens[num - 10] + " ";
        }
        return curr;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ?stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.numberToWords(n) << endl;
    
    return 0;
}
