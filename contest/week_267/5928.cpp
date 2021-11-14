#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual string decodeCiphertext(string encodedText, int rows) = 0;
};

class Solution_init : public Solution {
public:
    // iveo  |
    //   eed |
    //   l t |
    //    olc|
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        if (len == 0) return "";
        // very important optimization
        if (rows == 1) return encodedText;
        int cols = len / rows;
        
        // backward search the end, first non-empty char
        int startI = 0;
        int startJ = cols - 1;
        int i = startI;
        int j = startJ;
        string plainText = "";
        while (true) {
            char c = encodedText[i * cols + j];
            if (plainText.length() != 0 || c != ' ') plainText.insert(plainText.begin(), c);
            i--;
            j--;
            if (i == -1 && j == -1) break;
            if (i == -1) {
                if (startI != rows - 1) startI++;
                else startJ--;
                i = startI;
                j = startJ;
            }
        }
        //int k = plainText.size() - 1;
        //while (plainText[k] == ' ') plainText.erase(plainText.begin() + k);
        return plainText;
    }

private:
};

int main(int argc, char* argv[]) {
    int rows = argc >= 2 ? stoi(argv[1]) : 0;
    string s = argc >= 3 ? argv[2] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->decodeCiphertext(s, rows) << endl;

    return 0;
}
