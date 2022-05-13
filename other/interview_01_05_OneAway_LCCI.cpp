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
    virtual bool oneEditAway(string first, string second) = 0;
};

class Solution_init : public Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.length();
        int len2 = second.length();
        if (len1 < len2 - 1 || len1 > len2 + 1) return false;
        int i = 0;
        for (; i < len1 && i < len2 && first[i] == second[i]; i++);
        if (i == len1 || i == len2) return true;
        int j = i;
        if (len1 < len2) j++;
        else if (len1 > len2) i++;
        else {
            i++;
            j++;
        }
        for (; i < len1 && j < len2; i++, j++) if (first[i] != second[j]) return false;
        return true;
    }

private:
};

int main(int argc, char* argv[]) {
    string first = argc >= 2 ? argv[1] : "";
    string second = argc >= 3 ? argv[2] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->oneEditAway(first, second) << endl;

    return 0;
}
