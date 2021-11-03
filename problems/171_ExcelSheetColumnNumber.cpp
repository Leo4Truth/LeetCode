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
    int titleToNumber(string columnTitle) {
        int num = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            num *= 26;
            num += (int)(columnTitle[i] - 'A' + 1);
        }
        return num;
    }
};

int main(int argc, char* argv[]) {
    string columnTitle = argc >= 2 ? argv[1] : "A";

    Solution solution;
    cout << solution.titleToNumber(columnTitle) << endl;

    //system("pause");
    return 0;
}
