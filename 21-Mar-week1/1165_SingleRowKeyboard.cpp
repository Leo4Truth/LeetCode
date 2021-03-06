#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution1165 {
public:
    int calculateTime(string keyboard, string word) {
        int n = keyboard.size();
        int m = word.size();
        unordered_map<char, int> dict;
        for (int i = 0; i < n; i++) dict[keyboard[i]] = i;
        int res = 0;
        int pos = 0;
        for (int j = 0; j < m; j++) {
            if (res == 0) res += abs(dict[word[j]] - 0);
            else res += abs(dict[word[j]] - pos);
            pos = dict[word[j]];
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    string keyboard = argc >= 2 ? argv[1] : "";
    string word = argc >= 3 ? argv[2] : "";

    Solution1165 solution;
    cout << solution.calculateTime(keyboard, word) << endl;

    //system("pause");
    return 0;
}

