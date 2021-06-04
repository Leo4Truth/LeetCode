#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution246 {
public:
    bool isStroborgrammatic(string num) {
        int n = num.size();
        for (int i = 0; i <= n / 2; i++) {
            if (num[i] == '1' && num[n - 1 - i] == '1') continue;
            else if (num[i] == '6' && num[n - 1 - i] == '9') continue;
            else if (num[i] == '8' && num[n - 1 - i] == '8') continue;
            else if (num[i] == '9' && num[n - 1 - i] == '6') continue;
            else if (num[i] == '0' && num[n - 1 - i] == '0') continue;
            else return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    string num = argc >= 2 ? argv[1] : "69";

    Solution246 solution;
    cout << solution.isStroborgrammatic(num) << endl;

    //system("pause");
    return 0;
}

