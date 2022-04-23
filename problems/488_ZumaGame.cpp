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
    virtual int findMinStep(string board, string hand) = 0;
};

class Solution_init : public Solution {
public:
    int findMinStep(string board, string hand) {
        
        return 0;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string s = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();

    return 0;
}
